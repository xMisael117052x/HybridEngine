#pragma once
#include "Prerequisites.h"

/**
 * @brief Clase que encapsula el contexto de dispositivo DirectX para operaciones de renderizado.
 */
class
    DeviceContext {
public:
    /**
     * @brief Constructor por defecto.
     */
    DeviceContext() = default;
    
    /**
     * @brief Destructor por defecto.
     */
    ~DeviceContext() = default;

    /**
     * @brief Inicializa el contexto del dispositivo.
     */
    void
    init();

    /**
     * @brief Actualiza el estado del contexto del dispositivo.
     */
    void
    update();

    /**
     * @brief Realiza operaciones de renderizado utilizando el contexto del dispositivo.
     */
    void
    render();

    /**
     * @brief Libera los recursos utilizados por el contexto del dispositivo.
     */
    void
    destroy();
    
    /**
     * @brief Establece los viewports en la etapa de rasterizador.
     * @param NumViewports Número de viewports a establecer.
     * @param pViewports Puntero a los viewports.
     */
    void
    RSSetViewports(unsigned int NumViewports, const D3D11_VIEWPORT* pViewports);
    
    /**
     * @brief Limpia una vista de profundidad y estarcido.
     * @param pDepthStencilView Vista de profundidad y estarcido a limpiar.
     * @param ClearFlags Banderas que indican qué componentes limpiar.
     * @param Depth Valor de profundidad para la limpieza.
     * @param Stencil Valor de estarcido para la limpieza.
     */
    void
    ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView,
                          unsigned int ClearFlags,
                          float Depth,
                          UINT8 Stencil);
    
    /**
     * @brief Limpia una vista de destino de renderizado.
     * @param pRenderTargetView Vista de destino de renderizado a limpiar.
     * @param ColorRGBA Color RGBA para la limpieza.
     */
    void
    ClearRenderTargetView(ID3D11RenderTargetView* pRenderTargetView,
                          const float ColorRGBA[4]);
    
    /**
     * @brief Establece las vistas de destino de renderizado en la etapa de fusión de salida.
     * @param NumViews Número de vistas a establecer.
     * @param ppRenderTargetViews Puntero a las vistas de destino de renderizado.
     * @param pDepthStencilView Vista de profundidad y estarcido.
     */
    void
    OMSetRenderTargets(unsigned int NumViews,
                       ID3D11RenderTargetView* const* ppRenderTargetViews,
                       ID3D11DepthStencilView* pDepthStencilView);
    
    /**
     * @brief Establece la topología de primitivas en la etapa de ensamblaje de entrada.
     * @param Topology Topología a establecer.
     */
    void
    IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology);
    
    /**
     * @brief Establece los recursos de shader en la etapa de shader de píxeles.
     * @param StartSlot Slot inicial donde comenzar a establecer recursos.
     * @param NumViews Número de vistas de recursos a establecer.
     * @param ppShaderResourceViews Puntero a las vistas de recursos del shader.
     */
    void
    PSSetShaderResources(unsigned int StartSlot, unsigned int NumViews,
                         ID3D11ShaderResourceView* const* ppShaderResourceViews);
    
    /**
     * @brief Establece los muestreadores en la etapa de shader de píxeles.
     * @param StartSlot Slot inicial donde comenzar a establecer muestreadores.
     * @param NumSamplers Número de muestreadores a establecer.
     * @param ppSamplers Puntero a los estados de muestreador.
     */
    void
    PSSetSamplers(unsigned int StartSlot, unsigned int NumSamplers, ID3D11SamplerState* const* ppSamplers);
    
    /**
     * @brief Dibuja elementos indexados.
     * @param IndexCount Número de índices a dibujar.
     * @param StartIndexLocation Índice inicial en el búfer de índices.
     * @param BaseVertexLocation Valor a añadir a cada índice antes de leer la posición.
     */
    void
    DrawIndexed(unsigned int IndexCount, unsigned int StartIndexLocation, int BaseVertexLocation);
    
    /**
     * @brief Establece el estado de profundidad y estarcido en la etapa de fusión de salida.
     * @param pDepthStencilState Estado de profundidad y estarcido a establecer.
     * @param StencilRef Valor de referencia para comparaciones de estarcido.
     */
    void
    OMSetDepthStencilState(ID3D11DepthStencilState* pDepthStencilState, unsigned int StencilRef);
    
    /**
     * @brief Limpia todos los estados del contexto del dispositivo.
     */
    void
    ClearState();
    
    /**
     * @brief Establece el layout de entrada en la etapa de ensamblaje de entrada.
     * @param pInputLayout Layout de entrada a establecer.
     */
    void
    IASetInputLayout(ID3D11InputLayout* pInputLayout);
    
    /**
     * @brief Establece el shader de vértices.
     * @param pVertexShader Shader de vértices a establecer.
     * @param ppClassInstances Instancias de clase para el shader.
     * @param NumClassInstances Número de instancias de clase.
     */
    void
    VSSetShader(ID3D11VertexShader* pVertexShader, ID3D11ClassInstance* const* ppClassInstances,
                unsigned int NumClassInstances);
    
    /**
     * @brief Establece el shader de píxeles.
     * @param pPixelShader Shader de píxeles a establecer.
     * @param ppClassInstances Instancias de clase para el shader.
     * @param NumClassInstances Número de instancias de clase.
     */
    void
    PSSetShader(ID3D11PixelShader* pPixelShader, ID3D11ClassInstance* const* ppClassInstances,
                unsigned int NumClassInstances);
    
    /**
     * @brief Actualiza un subrecurso con nuevos datos.
     * @param pDstResource Recurso de destino.
     * @param DstSubresource Subrecurso de destino.
     * @param pDstBox Cuadro delimitador de destino.
     * @param pSrcData Datos de origen.
     * @param SrcRowPitch Pitch de fila de origen.
     * @param SrcDepthPitch Pitch de profundidad de origen.
     */
    void
    UpdateSubresource(ID3D11Resource* pDstResource,
                      unsigned int DstSubresource,
                      const D3D11_BOX* pDstBox,
                      const void* pSrcData,
                      unsigned int SrcRowPitch,
                      unsigned int SrcDepthPitch);
    
    /**
     * @brief Establece los búferes de vértices en la etapa de ensamblaje de entrada.
     * @param StartSlot Slot inicial donde comenzar a establecer búferes.
     * @param NumBuffers Número de búferes a establecer.
     * @param ppVertexBuffers Puntero a los búferes de vértices.
     * @param pStrides Tamaño en bytes de cada elemento de vértice.
     * @param pOffsets Desplazamiento en bytes desde el inicio de cada búfer.
     */
    void
    IASetVertexBuffers(unsigned int StartSlot,
                       unsigned int NumBuffers,
                       ID3D11Buffer* const* ppVertexBuffers,
                       const unsigned int* pStrides,
                       const unsigned int* pOffsets);
    
    /**
     * @brief Establece los búferes constantes en la etapa de shader de vértices.
     * @param StartSlot Slot inicial donde comenzar a establecer búferes.
     * @param NumBuffers Número de búferes a establecer.
     * @param ppConstantBuffers Puntero a los búferes constantes.
     */
    void
    VSSetConstantBuffers(unsigned int StartSlot, unsigned int NumBuffers, ID3D11Buffer* const* ppConstantBuffers);
    
    /**
     * @brief Establece los búferes constantes en la etapa de shader de píxeles.
     * @param StartSlot Slot inicial donde comenzar a establecer búferes.
     * @param NumBuffers Número de búferes a establecer.
     * @param ppConstantBuffers Puntero a los búferes constantes.
     */
    void
    PSSetConstantBuffers(unsigned int StartSlot, unsigned int NumBuffers, ID3D11Buffer* const* ppConstantBuffers);
    
    /**
     * @brief Establece el búfer de índices en la etapa de ensamblaje de entrada.
     * @param pIndexBuffer Búfer de índices a establecer.
     * @param Format Formato de los datos de índices.
     * @param Offset Desplazamiento en bytes desde el inicio del búfer.
     */
    void
    IASetIndexBuffer(ID3D11Buffer* pIndexBuffer, DXGI_FORMAT Format, unsigned int Offset);
    
    /**
     * @brief Establece el estado de mezcla en la etapa de fusión de salida.
     * @param pBlendState Estado de mezcla a establecer.
     * @param BlendFactor Factor de mezcla RGBA.
     * @param SampleMask Máscara de muestreo.
     */
    void
    OMSetBlendState(ID3D11BlendState* pBlendState, const float* BlendFactor, unsigned int SampleMask);

private:
    ID3D11DeviceContext* m_deviceContext = nullptr;

    friend class SwapChain;
    friend class BaseApp;
};
