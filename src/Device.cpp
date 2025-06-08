#include "Device.h"

/**
 * @brief Libera el dispositivo Direct3D.
 */
void
Device::destroy() {
	SAFE_RELEASE(m_device);
}

/**
 * @brief Crea una vista de destino de renderizado.
 * @param pResource El recurso de destino de renderizado.
 * @param pDesc La descripción de la vista de destino de renderizado.
 * @param ppRTView Puntero a la vista de destino de renderizado creada.
 * @return HRESULT El resultado de la operación.
 */
HRESULT
Device::CreateRenderTargetView(ID3D11Resource* pResource,
	const D3D11_RENDER_TARGET_VIEW_DESC* pDesc,
	ID3D11RenderTargetView** ppRTView) {
	if (!pResource) {
		ERROR("Device", "CreateRenderTargetView", "pResource is nullptr");
		return E_INVALIDARG;
	}
	if (!ppRTView) {
		ERROR("Device", "CreateRenderTargetView", "ppRTView is nullptr");
		return E_POINTER;
	}

	HRESULT hr = m_device->CreateRenderTargetView(pResource, pDesc, ppRTView);

	if (SUCCEEDED(hr)) {
		MESSAGE("Device", "CreateRenderTargetView",
			"Render Target View created successfully!");
	}
	else {
		ERROR("Device", "CreateRenderTargetView",
			("Failed to create Render Target View. HRESULT: " + std::to_string(hr)).c_str());
	}

	return hr;
}

/**
 * @brief Crea una textura 2D.
 * @param pDesc La descripción de la textura 2D.
 * @param pInitialData Los datos iniciales de la textura.
 * @param ppTexture2D Puntero a la textura 2D creada.
 * @return HRESULT El resultado de la operación.
 */
HRESULT
Device::CreateTexture2D(const D3D11_TEXTURE2D_DESC* pDesc,
												const D3D11_SUBRESOURCE_DATA* pInitialData,
												ID3D11Texture2D** ppTexture2D) {
	if (!pDesc) {
		ERROR("Device", "CreateTexture2D", "pDesc is nullptr");
		return E_INVALIDARG;
	}
	if (!ppTexture2D) {
		ERROR("Device", "CreateTexture2D", "ppTexture2D is nullptr");
		return E_POINTER;
	}

	HRESULT hr = m_device->CreateTexture2D(pDesc, pInitialData, ppTexture2D);

	if (SUCCEEDED(hr)) {
		MESSAGE("Device", "CreateTexture2D",
			"Texture2D created successfully!");
	}
	else {
		ERROR("Device", "CreateTexture2D",
			("Failed to create Texture2D. HRESULT: " + std::to_string(hr)).c_str());
	}

	return hr;
}

/**
 * @brief Crea una vista de plantilla de profundidad.
 * @param pResource El recurso de plantilla de profundidad.
 * @param pDesc La descripción de la vista de plantilla de profundidad.
 * @param ppDepthStencilView Puntero a la vista de plantilla de profundidad creada.
 * @return HRESULT El resultado de la operación.
 */
HRESULT
Device::CreateDepthStencilView(ID3D11Resource* pResource,
	const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
	ID3D11DepthStencilView** ppDepthStencilView) {
	if (!pResource) {
		ERROR("Device", "CreateDepthStencilView", "pResource is nullptr");
		return E_INVALIDARG;
	}
	if (!ppDepthStencilView) {
		ERROR("Device", "CreateDepthStencilView", "ppDepthStencilView is nullptr");
		return E_POINTER;
	}

	HRESULT hr = m_device->CreateDepthStencilView(pResource, pDesc, ppDepthStencilView);

	if (SUCCEEDED(hr)) {
		MESSAGE("Device", "CreateDepthStencilView",
			"Depth Stencil View created successfully!");
	}
	else {
		ERROR("Device", "CreateDepthStencilView",
			("Failed to create Depth Stencil View. HRESULT: " + std::to_string(hr)).c_str());
	}

	return hr;
}

/**
 * @brief Crea un sombreador de vértices.
 * @param pShaderBytecode Puntero al bytecode del sombreador.
 * @param BytecodeLength Longitud del bytecode del sombreador.
 * @param pClassLinkage Puntero a la interfaz de enlace de clases.
 * @param ppVertexShader Puntero al sombreador de vértices creado.
 * @return HRESULT El resultado de la operación.
 */
HRESULT
Device::CreateVertexShader(const void* pShaderBytecode,
	unsigned int BytecodeLength,
	ID3D11ClassLinkage* pClassLinkage,
	ID3D11VertexShader** ppVertexShader) {
	if (!pShaderBytecode) {
		ERROR("Device", "CreateVertexShader", "pShaderBytecode is nullptr");
		return E_INVALIDARG;
	}
	if (!ppVertexShader) {
		ERROR("Device", "CreateVertexShader", "ppVertexShader is nullptr");
		return E_POINTER;
	}

	HRESULT hr = m_device->CreateVertexShader(pShaderBytecode,
		BytecodeLength,
		pClassLinkage,
		ppVertexShader);

	if (SUCCEEDED(hr)) {
		MESSAGE("Device", "CreateVertexShader",
			"Vertex Shader created successfully!");
	}
	else {
		ERROR("Device", "CreateVertexShader",
			("Failed to create Vertex Shader. HRESULT: " + std::to_string(hr)).c_str());
	}

	return hr;
}

/**
 * @brief Crea un diseño de entrada.
 * @param pInputElementDescs Descripciones de los elementos de entrada.
 * @param NumElements Número de elementos de entrada.
 * @param pShaderBytecodeWithInputSignature Puntero al bytecode del sombreador con firma de entrada.
 * @param BytecodeLength Longitud del bytecode del sombreador.
 * @param ppInputLayout Puntero al diseño de entrada creado.
 * @return HRESULT El resultado de la operación.
 */
HRESULT
Device::CreateInputLayout(const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs,
	unsigned int NumElements,
	const void* pShaderBytecodeWithInputSignature,
	unsigned int BytecodeLength,
	ID3D11InputLayout** ppInputLayout) {
	if (!pInputElementDescs) {
		ERROR("Device", "CreateInputLayout", "pInputElementDescs is nullptr");
		return E_INVALIDARG;
	}
	if (!ppInputLayout) {
		ERROR("Device", "CreateInputLayout", "ppInputLayout is nullptr");
		return E_POINTER;
	}

	HRESULT hr = m_device->CreateInputLayout(pInputElementDescs,
		NumElements,
		pShaderBytecodeWithInputSignature,
		BytecodeLength,
		ppInputLayout);

	if (SUCCEEDED(hr)) {
		MESSAGE("Device", "CreateInputLayout",
			"Input Layout created successfully!");
	}
	else {
		ERROR("Device", "CreateInputLayout",
			("Failed to create Input Layout. HRESULT: " + std::to_string(hr)).c_str());
	}

	return hr;
}

/**
 * @brief Crea un sombreador de píxeles.
 * @param pShaderBytecode Puntero al bytecode del sombreador.
 * @param BytecodeLength Longitud del bytecode del sombreador.
 * @param pClassLinkage Puntero a la interfaz de enlace de clases.
 * @param ppPixelShader Puntero al sombreador de píxeles creado.
 * @return HRESULT El resultado de la operación.
 */
HRESULT
Device::CreatePixelShader(const void* pShaderBytecode,
	unsigned int BytecodeLength,
	ID3D11ClassLinkage* pClassLinkage,
	ID3D11PixelShader** ppPixelShader) {
	if (!pShaderBytecode) {
		ERROR("Device", "CreatePixelShader", "pShaderBytecode is nullptr");
		return E_INVALIDARG;
	}
	if (!ppPixelShader) {
		ERROR("Device", "CreatePixelShader", "ppPixelShader is nullptr");
		return E_POINTER;
	}

	HRESULT hr = m_device->CreatePixelShader(pShaderBytecode,
		BytecodeLength,
		pClassLinkage,
		ppPixelShader);

	if (SUCCEEDED(hr)) {
		MESSAGE("Device", "CreatePixelShader",
			"Pixel Shader created successfully!");
	}
	else {
		ERROR("Device", "CreatePixelShader",
			("Failed to create Pixel Shader. HRESULT: " + std::to_string(hr)).c_str());
	}

	return hr;
}

/**
 * @brief Crea un estado de muestreador.
 * @param pSamplerDesc La descripción del estado de muestreador.
 * @param ppSamplerState Puntero al estado de muestreador creado.
 * @return HRESULT El resultado de la operación.
 */
HRESULT
Device::CreateSamplerState(const D3D11_SAMPLER_DESC* pSamplerDesc,
	ID3D11SamplerState** ppSamplerState) {
	if (!pSamplerDesc) {
		ERROR("Device", "CreateSamplerState", "pSamplerDesc is nullptr");
		return E_INVALIDARG;
	}
	if (!ppSamplerState) {
		ERROR("Device", "CreateSamplerState", "ppSamplerState is nullptr");
		return E_POINTER;
	}

	HRESULT hr = m_device->CreateSamplerState(pSamplerDesc, ppSamplerState);

	if (SUCCEEDED(hr)) {
		MESSAGE("Device", "CreateSamplerState",
			"Sampler State created successfully!");
	}
	else {
		ERROR("Device", "CreateSamplerState",
			("Failed to create Sampler State. HRESULT: " + std::to_string(hr)).c_str());
	}

	return hr;
}

/**
 * @brief Crea un búfer.
 * @param pDesc La descripción del búfer.
 * @param pInitialData Los datos iniciales del búfer.
 * @param ppBuffer Puntero al búfer creado.
 * @return HRESULT El resultado de la operación.
 */
HRESULT
Device::CreateBuffer(const D3D11_BUFFER_DESC* pDesc,
	const D3D11_SUBRESOURCE_DATA* pInitialData,
	ID3D11Buffer** ppBuffer) {
	if (!pDesc) {
		ERROR("Device", "CreateBuffer", "pDesc is nullptr");
		return E_INVALIDARG;
	}
	if (!ppBuffer) {
		ERROR("Device", "CreateBuffer", "ppBuffer is nullptr");
		return E_POINTER;
	}

	HRESULT hr = m_device->CreateBuffer(pDesc, pInitialData, ppBuffer);

	if (SUCCEEDED(hr)) {
		MESSAGE("Device", "CreateBuffer",
			"Buffer created successfully!");
	}
	else {
		ERROR("Device", "CreateBuffer",
			("Failed to create Buffer. HRESULT: " + std::to_string(hr)).c_str());

	}
	return hr;
}

/**
 * @brief Crea un estado de mezcla.
 * @param pBlendStateDesc La descripción del estado de mezcla.
 * @param ppBlendState Puntero al estado de mezcla creado.
 * @return HRESULT El resultado de la operación.
 */
HRESULT 
Device::CreateBlendState(const D3D11_BLEND_DESC* pBlendStateDesc, 
												 ID3D11BlendState** ppBlendState) {
	if (!pBlendStateDesc) {
		ERROR("Device", "CreateBlendState", "pBlendStateDesc is nullptr");
		return E_INVALIDARG;
	}
	if (!ppBlendState) {
		ERROR("Device", "CreateBlendState", "ppBlendState is nullptr");
		return E_POINTER;
	}

	HRESULT hr = m_device->CreateBlendState(pBlendStateDesc, ppBlendState);
	
	if (SUCCEEDED(hr)) {
		MESSAGE("Device", "CreateBlendState",
			"Blend State created successfully!");
	}
	else {
		ERROR("Device", "CreateBlendState",
			("Failed to create Blend State. HRESULT: " + std::to_string(hr)).c_str());
	}
	return hr;
}

/**
 * @brief Crea un estado de plantilla de profundidad.
 * @param pDepthStencilDesc La descripción del estado de plantilla de profundidad.
 * @param ppDepthStencilState Puntero al estado de plantilla de profundidad creado.
 * @return HRESULT El resultado de la operación.
 */
HRESULT 
Device::CreateDepthStencilState(const D3D11_DEPTH_STENCIL_DESC* pDepthStencilDesc, 
																ID3D11DepthStencilState** ppDepthStencilState) {
	if (!pDepthStencilDesc) {
		ERROR("Device", "CreateDepthStencilState", "pDepthStencilDesc is nullptr");
		return E_INVALIDARG;
	}
	if (!ppDepthStencilState) {
		ERROR("Device", "CreateDepthStencilState", "ppDepthStencilState is nullptr");
		return E_POINTER;
	}	

	HRESULT hr = m_device->CreateDepthStencilState(pDepthStencilDesc, ppDepthStencilState);

	if (SUCCEEDED(hr)) {
		MESSAGE("Device", "CreateDepthStencilState",
			"Depth Stencil State created successfully!");
	}
	else {
		ERROR("Device", "CreateDepthStencilState",
			("Failed to create Depth Stencil State. HRESULT: " + std::to_string(hr)).c_str());
	}

	return hr;
}

/**
 * @brief Crea un estado de rasterizador.
 * @param pRasterizerDesc La descripción del estado de rasterizador.
 * @param ppRasterizerState Puntero al estado de rasterizador creado.
 * @return HRESULT El resultado de la operación.
 */
HRESULT 
Device::CreateRasterizerState(const D3D11_RASTERIZER_DESC* pRasterizerDesc, 
															ID3D11RasterizerState** ppRasterizerState) {
	if (!pRasterizerDesc) {
		ERROR("Device", "CreateRasterizerState", "pRasterizerDesc is nullptr");
		return E_INVALIDARG;
	}
	if (!ppRasterizerState) {
		ERROR("Device", "CreateRasterizerState", "ppRasterizerState is nullptr");
		return E_POINTER;
	}

	HRESULT hr = m_device->CreateRasterizerState(pRasterizerDesc, ppRasterizerState);

	if (SUCCEEDED(hr)) {
		MESSAGE("Device", "CreateRasterizerState",
			"Rasterizer State created successfully!");
	}
	else {
		ERROR("Device", "CreateRasterizerState",
			("Failed to create Rasterizer State. HRESULT: " + std::to_string(hr)).c_str());
	}

	return hr;
}