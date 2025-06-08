#include "RenderTargetView.h"
#include "Device.h"
#include "Texture.h"
#include "DeviceContext.h"
#include "DepthStencilView.h"

/**
 * @brief Inicializa la vista de destino de renderizado.
 * @param device El dispositivo Direct3D.
 * @param backBuffer La textura del búfer de reserva.
 * @param Format El formato de la vista de destino de renderizado.
 * @return HRESULT El resultado de la operación.
 */
HRESULT 
RenderTargetView::init(Device& device, Texture& backBuffer, DXGI_FORMAT Format) {
	if (!device.m_device) {
		ERROR("RenderTargetView", "init",	"Device is nullptr.");
		return E_POINTER;
	}
	if (!backBuffer.m_texture) {
		ERROR("RenderTargetView", "init", "Texture is nullptr.");
		return E_POINTER;
	}
	if (Format == DXGI_FORMAT_UNKNOWN) {
		ERROR("RenderTargetView", "init", "Format is DXGI_FORMAT_UNKNOWN.");
		return E_INVALIDARG;
	}

	D3D11_RENDER_TARGET_VIEW_DESC desc;
	memset(&desc, 0, sizeof(desc));
	desc.Format = Format;
	desc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2DMS;

	HRESULT hr = device.m_device->CreateRenderTargetView(backBuffer.m_texture, 
																											 &desc, 
																											 &m_renderTargetView);
	if (FAILED(hr)) {
		ERROR("RenderTargetView", "init", 
			("Failed to create render target view. HRESULT: " + std::to_string(hr)).c_str());
		return hr;
	}

	return S_OK;
}

/**
 * @brief Inicializa la vista de destino de renderizado.
 * @param device El dispositivo Direct3D.
 * @param inTex La textura de entrada.
 * @param ViewDimension La dimensión de la vista.
 * @param Format El formato de la vista de destino de renderizado.
 * @return HRESULT El resultado de la operación.
 */
HRESULT 
RenderTargetView::init(Device& device, 
											 Texture& inTex, 
											 D3D11_RTV_DIMENSION ViewDimension, 
											 DXGI_FORMAT Format) {
	if (!device.m_device) {
		ERROR("RenderTargetView", "init", "Device is nullptr.");
		return E_POINTER;
	}
	if (!inTex.m_texture) {
		ERROR("RenderTargetView", "init", "Texture is nullptr.");
		return E_POINTER;
	}
	if (Format == DXGI_FORMAT_UNKNOWN) {
		ERROR("RenderTargetView", "init", "Format is DXGI_FORMAT_UNKNOWN.");
		return E_INVALIDARG;
	}

	D3D11_RENDER_TARGET_VIEW_DESC desc;
	memset(&desc, 0, sizeof(desc));
	desc.Format = Format;
	desc.ViewDimension = ViewDimension;

	HRESULT hr = device.m_device->CreateRenderTargetView(inTex.m_texture, 
																											 &desc, 
																											 &m_renderTargetView);

	if (FAILED(hr)) {
		ERROR("RenderTargetView", "init", 
			("Failed to create render target view. HRESULT: " + std::to_string(hr)).c_str());
		return hr;
	}

	return S_OK;
}

/**
 * @brief Establece la vista de destino de renderizado y la vista de plantilla de profundidad.
 * @param deviceContext El contexto del dispositivo Direct3D.
 * @param depthStencilView La vista de plantilla de profundidad.
 * @param numViews El número de vistas de destino de renderizado.
 * @param ClearColor El color para limpiar la vista de destino de renderizado.
 */
void 
RenderTargetView::render(DeviceContext& deviceContext, 
												 DepthStencilView& depthStencilView, 
												 unsigned int numViews, 
												 const float ClearColor[4]) {
	if (!deviceContext.m_deviceContext) {
		ERROR("RenderTargetView", "render", "DeviceContext is nullptr.");
		return;
	}
	if (!m_renderTargetView) {
		ERROR("RenderTargetView", "render", "RenderTargetView is nullptr.");
		return;
	}

	deviceContext.m_deviceContext->ClearRenderTargetView(m_renderTargetView, ClearColor);

	deviceContext.m_deviceContext->OMSetRenderTargets(numViews, 
																										&m_renderTargetView, 
																										depthStencilView.m_depthStencilView);
}

/**
 * @brief Establece la vista de destino de renderizado.
 * @param deviceContext El contexto del dispositivo Direct3D.
 * @param numViews El número de vistas de destino de renderizado.
 */
void 
RenderTargetView::render(DeviceContext& deviceContext, unsigned int numViews) {
	if (!deviceContext.m_deviceContext) {
		ERROR("RenderTargetView", "render", "DeviceContext is nullptr.");
		return;
	}
	if (!m_renderTargetView) {
		ERROR("RenderTargetView", "render", "RenderTargetView is nullptr.");
		return;
	}
	deviceContext.m_deviceContext->OMSetRenderTargets(numViews, 
																										&m_renderTargetView, 
																										nullptr);
}

/**
 * @brief Libera los recursos de la vista de destino de renderizado.
 */
void RenderTargetView::destroy() {
	SAFE_RELEASE(m_renderTargetView);
}