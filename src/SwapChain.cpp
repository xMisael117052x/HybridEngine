#include "SwapChain.h"
#include "Device.h"
#include "DeviceContext.h"
#include "Window.h"

/**
 * @brief Inicializa la cadena de intercambio.
 * @param device El dispositivo Direct3D.
 * @param deviceContext El contexto del dispositivo Direct3D.
 * @param backBuffer La textura del búfer de reserva (ID3D11Texture2D**).
 * @param window La ventana de la aplicación.
 * @return HRESULT El resultado de la operación.
 */
HRESULT 
SwapChain::init(Device& device, 
								DeviceContext& deviceContext, 
								ID3D11Texture2D** backBuffer, // Cambiado para aceptar ID3D11Texture2D** directamente
								Window window) {
	if (!window.m_hWnd) {
		ERROR("SwapChain", "init", "Invalid window handle. (m_hWnd is nullptr)");
		return E_POINTER;
	}

	HRESULT hr = S_OK;

  unsigned int createDeviceFlags = 0;
#ifdef _DEBUG
  createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

  D3D_DRIVER_TYPE driverTypes[] = {
      D3D_DRIVER_TYPE_HARDWARE,
      D3D_DRIVER_TYPE_WARP,
      D3D_DRIVER_TYPE_REFERENCE,
  };
  unsigned int numDriverTypes = ARRAYSIZE(driverTypes);

  D3D_FEATURE_LEVEL featureLevels[] = {
      D3D_FEATURE_LEVEL_11_0,
      D3D_FEATURE_LEVEL_10_1,
      D3D_FEATURE_LEVEL_10_0,
  };
  unsigned int numFeatureLevels = ARRAYSIZE(featureLevels);

  for (unsigned int driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++) {
    D3D_DRIVER_TYPE driverType = driverTypes[driverTypeIndex];
    hr = D3D11CreateDevice(
        nullptr,
        driverType,
        nullptr,
        createDeviceFlags,
        featureLevels,
        numFeatureLevels,
        D3D11_SDK_VERSION,
        &device.m_device,
        &this->m_featureLevel,
        &deviceContext.m_deviceContext);

    if (SUCCEEDED(hr)) {
			MESSAGE("SwapChain", "init", "Device created successfully.");
      break;
    }
	}

  if (FAILED(hr)) {
    ERROR("SwapChain", "init", 
      ("Failed to create D3D11 device. HRESULT: " + std::to_string(hr)).c_str());
    return hr;
  }

  this->m_sampleCount = 4;
  hr = device.m_device->CheckMultisampleQualityLevels(DXGI_FORMAT_R8G8B8A8_UNORM, 
                                                      this->m_sampleCount, 
                                                      &this->m_qualityLevels);
  if (FAILED(hr) || this->m_qualityLevels == 0) {
    ERROR("SwapChain", "init",
      ("MSAA not supported or invalid quality level. HRESULT: " + std::to_string(hr)).c_str());
    return hr;
  }

  DXGI_SWAP_CHAIN_DESC sd;
  memset(&sd,0, sizeof(sd));
  sd.BufferCount = 1;
  sd.BufferDesc.Width = window.m_width;
  sd.BufferDesc.Height = window.m_height;
  sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
  sd.BufferDesc.RefreshRate.Numerator = 60;
  sd.BufferDesc.RefreshRate.Denominator = 1;
  sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
  sd.OutputWindow = window.m_hWnd;
  sd.Windowed = TRUE; 
  sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
  sd.SampleDesc.Count = this->m_sampleCount;
  sd.SampleDesc.Quality = this->m_qualityLevels - 1;

	hr = device.m_device->QueryInterface(__uuidof(IDXGIDevice), (void**)&this->m_dxgiDevice);
  if (FAILED(hr)) {
    ERROR("SwapChain", "init", 
      ("Failed to query IDXGIDevice. HRESULT: " + std::to_string(hr)).c_str());
    return hr;
	}

	hr = this->m_dxgiDevice->GetAdapter(&this->m_dxgiAdapter);
  if (FAILED(hr)) {
    ERROR("SwapChain", "init", 
      ("Failed to get IDXGIAdapter. HRESULT: " + std::to_string(hr)).c_str());
    return hr;
	}

  hr = this->m_dxgiAdapter->GetParent(__uuidof(IDXGIFactory), 
                                reinterpret_cast<void**>(&this->m_dxgiFactory));
  if (FAILED(hr)) {
    ERROR("SwapChain", "init", 
      ("Failed to get IDXGIFactory. HRESULT: " + std::to_string(hr)).c_str());
    return hr;
	}

  hr = this->m_dxgiFactory->CreateSwapChain(device.m_device, &sd, &this->m_swapChain);

  if (FAILED(hr)) {
    ERROR("SwapChain", "init", 
      ("Failed to create swap chain. HRESULT: " + std::to_string(hr)).c_str());
    return hr;
	}

  hr = m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), 
                              reinterpret_cast<void**>(backBuffer)); // Se usa directamente backBuffer
  if (FAILED(hr)) {
    ERROR("SwapChain", "init", 
      ("Failed to get back buffer. HRESULT: " + std::to_string(hr)).c_str());
    return hr;
	}

	return S_OK;
}

/**
 * @brief Libera los recursos de la cadena de intercambio.
 */
void 
SwapChain::destroy() {
  if (this->m_swapChain) {
		SAFE_RELEASE(this->m_swapChain);
  }
  if (this->m_dxgiDevice) {
    SAFE_RELEASE(this->m_dxgiDevice);
  }
  if (this->m_dxgiAdapter) {
    SAFE_RELEASE(this->m_dxgiAdapter);
	}
  if (this->m_dxgiFactory) {
    SAFE_RELEASE(this->m_dxgiFactory);
  }
}

/**
 * @brief Presenta el contenido de la cadena de intercambio.
 */
void 
SwapChain::present() {
  if (this->m_swapChain) {
    HRESULT hr = this->m_swapChain->Present(0, 0);
    if (FAILED(hr)) {
      ERROR("SwapChain", "present", 
        ("Failed to present swap chain. HRESULT: " + std::to_string(hr)).c_str());
    }
  } else {
    ERROR("SwapChain", "present", "Swap chain is not initialized.");
	}
}
