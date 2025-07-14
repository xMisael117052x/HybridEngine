#pragma once
#include "Prerequisites.h"

/**
 * @brief Clase que encapsula un dispositivo DirectX para la creación de recursos gráficos.
 */
class 
Device {
public:
	/**
	 * @brief Constructor por defecto.
	 */
	Device() = default;
	
	/**
	 * @brief Destructor por defecto.
	 */
	~Device()= default;

	/**
	 * @brief Inicializa el dispositivo DirectX.
	 */
	void
	init();
	
	/**
	 * @brief Actualiza el estado del dispositivo si es necesario.
	 */
	void 
	update();
	
	/**
	 * @brief Realiza operaciones de renderizado relacionadas con el dispositivo.
	 */
	void 
	render();
	
	/**
	 * @brief Libera los recursos utilizados por el dispositivo.
	 */
	void 
	destroy();
    
	/**
	 * @brief Crea una vista de destino de renderizado.
	 * @param pResource Recurso asociado a la vista.
	 * @param pDesc Descripción de la vista.
	 * @param ppRTView Puntero donde se almacenará la vista creada.
	 * @return Código HRESULT que indica el éxito o fracaso de la operación.
	 */
	HRESULT 
	CreateRenderTargetView(ID3D11Resource *pResource,
												 const D3D11_RENDER_TARGET_VIEW_DESC *pDesc,
												 ID3D11RenderTargetView **ppRTView);
    
	/**
	 * @brief Crea una textura 2D.
	 * @param pDesc Descripción de la textura.
	 * @param pInitialData Datos iniciales para la textura.
	 * @param ppTexture2D Puntero donde se almacenará la textura creada.
	 * @return Código HRESULT que indica el éxito o fracaso de la operación.
	 */
	HRESULT
	CreateTexture2D(const D3D11_TEXTURE2D_DESC* pDesc,
									const D3D11_SUBRESOURCE_DATA* pInitialData,
									ID3D11Texture2D** ppTexture2D);
    
	/**
	 * @brief Crea una vista de profundidad y estarcido.
	 * @param pResource Recurso asociado a la vista.
	 * @param pDesc Descripción de la vista.
	 * @param ppDepthStencilView Puntero donde se almacenará la vista creada.
	 * @return Código HRESULT que indica el éxito o fracaso de la operación.
	 */
	HRESULT 
	CreateDepthStencilView(ID3D11Resource* pResource,
												 const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
												 ID3D11DepthStencilView** ppDepthStencilView);
    
	/**
	 * @brief Crea un shader de vértices.
	 * @param pShaderBytecode Código compilado del shader.
	 * @param BytecodeLength Tamaño del código compilado.
	 * @param pClassLinkage Enlace de clases para el shader.
	 * @param ppVertexShader Puntero donde se almacenará el shader creado.
	 * @return Código HRESULT que indica el éxito o fracaso de la operación.
	 */
	HRESULT 
	CreateVertexShader(const void* pShaderBytecode,
										 unsigned int BytecodeLength,
										 ID3D11ClassLinkage* pClassLinkage,
										 ID3D11VertexShader** ppVertexShader);
    
	/**
	 * @brief Crea un layout de entrada para el shader de vértices.
	 * @param pInputElementDescs Descripción de los elementos de entrada.
	 * @param NumElements Número de elementos de entrada.
	 * @param pShaderBytecodeWithInputSignature Código compilado del shader con firma de entrada.
	 * @param BytecodeLength Tamaño del código compilado.
	 * @param ppInputLayout Puntero donde se almacenará el layout creado.
	 * @return Código HRESULT que indica el éxito o fracaso de la operación.
	 */
	HRESULT 
	CreateInputLayout(const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs,
										unsigned int NumElements,
										const void* pShaderBytecodeWithInputSignature,
										unsigned int BytecodeLength,
										ID3D11InputLayout** ppInputLayout);
    
	/**
	 * @brief Crea un shader de píxeles.
	 * @param pShaderBytecode Código compilado del shader.
	 * @param BytecodeLength Tamaño del código compilado.
	 * @param pClassLinkage Enlace de clases para el shader.
	 * @param ppPixelShader Puntero donde se almacenará el shader creado.
	 * @return Código HRESULT que indica el éxito o fracaso de la operación.
	 */
	HRESULT 
	CreatePixelShader(const void* pShaderBytecode,
										unsigned int BytecodeLength,
										ID3D11ClassLinkage* pClassLinkage,
										ID3D11PixelShader** ppPixelShader);
    
	/**
	 * @brief Crea un búfer.
	 * @param pDesc Descripción del búfer.
	 * @param pInitialData Datos iniciales para el búfer.
	 * @param ppBuffer Puntero donde se almacenará el búfer creado.
	 * @return Código HRESULT que indica el éxito o fracaso de la operación.
	 */
	HRESULT 
	CreateBuffer(const D3D11_BUFFER_DESC* pDesc,
							 const D3D11_SUBRESOURCE_DATA* pInitialData,
							 ID3D11Buffer** ppBuffer);
    
	/**
	 * @brief Crea un estado de muestreador.
	 * @param pSamplerDesc Descripción del estado de muestreador.
	 * @param ppSamplerState Puntero donde se almacenará el estado creado.
	 * @return Código HRESULT que indica el éxito o fracaso de la operación.
	 */
	HRESULT
	CreateSamplerState(const D3D11_SAMPLER_DESC *pSamplerDesc,
										 ID3D11SamplerState** ppSamplerState);
    
	/**
	 * @brief Crea un estado de mezcla.
	 * @param pBlendStateDesc Descripción del estado de mezcla.
	 * @param ppBlendState Puntero donde se almacenará el estado creado.
	 * @return Código HRESULT que indica el éxito o fracaso de la operación.
	 */
	HRESULT 
	CreateBlendState(const D3D11_BLEND_DESC* pBlendStateDesc,
									 ID3D11BlendState** ppBlendState);
    
	/**
	 * @brief Crea un estado de profundidad y estarcido.
	 * @param pDepthStencilDesc Descripción del estado de profundidad y estarcido.
	 * @param ppDepthStencilState Puntero donde se almacenará el estado creado.
	 * @return Código HRESULT que indica el éxito o fracaso de la operación.
	 */
	HRESULT 
	CreateDepthStencilState(const D3D11_DEPTH_STENCIL_DESC* pDepthStencilDesc,
													ID3D11DepthStencilState** ppDepthStencilState);
    
	/**
	 * @brief Crea un estado de rasterizador.
	 * @param pRasterizerDesc Descripción del estado de rasterizador.
	 * @param ppRasterizerState Puntero donde se almacenará el estado creado.
	 * @return Código HRESULT que indica el éxito o fracaso de la operación.
	 */
	HRESULT
	CreateRasterizerState(const D3D11_RASTERIZER_DESC* pRasterizerDesc,
												ID3D11RasterizerState** ppRasterizerState);
public:
	ID3D11Device* m_device = nullptr;
};
