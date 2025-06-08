#include "Texture.h"
#include "Device.h"
#include "DeviceContext.h"

/**
 * @brief Inicializa la textura desde un archivo.
 * @param device El dispositivo Direct3D.
 * @param textureName El nombre del archivo de textura.
 * @param extensionType El tipo de extensión del archivo.
 * @return HRESULT El resultado de la operación.
 */
HRESULT Texture::init(Device device, const std::string& textureName, ExtensionType extensionType)
{
	return E_NOTIMPL;
}

/**
 * @brief Inicializa la textura con dimensiones y formato específicos.
 * @param device El dispositivo Direct3D.
 * @param width El ancho de la textura.
 * @param height El alto de la textura.
 * @param Format El formato de la textura.
 * @param BindFlags Los indicadores de enlace de recursos.
 * @param sampleCount El número de muestras para MSAA.
 * @param qualityLevels Los niveles de calidad para MSAA.
 * @return HRESULT El resultado de la operación.
 */
HRESULT
Texture::init(Device device, 
							unsigned int width, 
							unsigned int height, 
							DXGI_FORMAT Format, 
							unsigned int BindFlags, 
							unsigned int sampleCount, 
							unsigned int qualityLevels ) {
	if (!device.m_device) {
		ERROR("DepthStencilView", "init", "Device is null.");
		return E_POINTER;
	}
	if (width == 0 || height == 0) {
		ERROR("Texture", "init", "Width and height must be greater than 0");
		E_INVALIDARG;
	}

	D3D11_TEXTURE2D_DESC desc;
	memset(&desc, 0, sizeof(desc));
	desc.Width = width;
	desc.Height = height;
	desc.MipLevels = 1;
	desc.ArraySize = 1;
	desc.Format = Format;
	desc.SampleDesc.Count = sampleCount;
	desc.SampleDesc.Quality = qualityLevels;
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.BindFlags = BindFlags;
	desc.CPUAccessFlags = 0;
	desc.MiscFlags = 0;

	HRESULT hr = device.CreateTexture2D(&desc, nullptr, &m_texture);

	if (FAILED(hr)) {
		ERROR("Texture", "init",
			("Failed to create texture with specified params. HRESULT: " + std::to_string(hr)).c_str());
		return hr;
	}

	return S_OK;
}

/**
 * @brief Inicializa la textura como una vista de recurso de sombreador desde otra textura.
 * @param device El dispositivo Direct3D.
 * @param textureRef La textura de referencia.
 * @param format El formato de la vista de recurso de sombreador.
 * @return HRESULT El resultado de la operación.
 */
HRESULT
Texture::init(Device& device, Texture& textureRef, DXGI_FORMAT format) {
	if (!device.m_device) {
		ERROR("Texture", "init", "Device is null.");
		return E_POINTER;
	}
	if (!textureRef.m_texture) {
		ERROR("Texture", "init", "Texture is null.");
		return E_POINTER;
	}

	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
	srvDesc.Format = format;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srvDesc.Texture2D.MipLevels = 1;
	srvDesc.Texture2D.MostDetailedMip = 0;

	HRESULT hr = device.m_device->CreateShaderResourceView(textureRef.m_texture, 
															 &srvDesc, 
															 &m_textureFromImg);

	if (FAILED(hr)) {
		ERROR("Texture", "init",
			("Failed to create shader resource view for PNG textures. HRESULT: " + std::to_string(hr)).c_str());
		return hr;
	}

	return S_OK;
}

/**
 * @brief Función que actualiza el recurso de textura.
 */
void Texture::update() {

}

/**
 * @brief Renderiza la textura.
 * @param deviceContext El contexto del dispositivo Direct3D.
 * @param StartSlot El slot de inicio para enlazar la vista de recurso de sombreador.
 * @param NumViews El número de vistas a enlazar.
 */
void 
Texture::render(DeviceContext& deviceContext, 
								unsigned int StartSlot, 
								unsigned int NumViews) {
	if (!deviceContext.m_deviceContext) {
		ERROR("DepthStencilView", "render", "Device context is null.");
		return;
	}

	if (m_textureFromImg) {
		ID3D11ShaderResourceView* nullSRV[] = { nullptr };
		deviceContext.m_deviceContext->PSSetShaderResources(StartSlot, NumViews, nullSRV);
		deviceContext.m_deviceContext->PSSetShaderResources(StartSlot, NumViews, &m_textureFromImg);
	}
}

/**
 * @brief Libera los recursos de la textura.
 */
void Texture::destroy() {
	if (m_texture != nullptr) {
		SAFE_RELEASE(m_texture);
	}
	else if (m_textureFromImg != nullptr) {
		SAFE_RELEASE(m_textureFromImg);
	}
}
