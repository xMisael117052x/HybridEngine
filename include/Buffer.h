#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;
class MeshComponent;

/**
 * @brief Clase que gestiona los búferes de DirectX, como búferes de vértices, índices y constantes.
 */
class 
Buffer {
public:
    /**
     * @brief Constructor por defecto.
     */
    Buffer()  = default;
    
    /**
     * @brief Destructor por defecto.
     */
    ~Buffer() = default;

    /**
     * @brief Inicializa un búfer a partir de un componente de malla.
     * @param device Referencia al dispositivo DirectX.
     * @param mesh Componente de malla que contiene los datos para el búfer.
     * @param bindFlag Bandera que indica el tipo de búfer a crear.
     * @return Código HRESULT que indica el éxito o fracaso de la inicialización.
     */
    HRESULT
    init(Device& device, const MeshComponent& mesh, unsigned int bindFlag);

    /**
     * @brief Inicializa un búfer con un tamaño específico.
     * @param device Referencia al dispositivo DirectX.
     * @param ByteWidth Tamaño del búfer en bytes.
     * @return Código HRESULT que indica el éxito o fracaso de la inicialización.
     */
    HRESULT
    init(Device& device, unsigned int ByteWidth);

    /**
     * @brief Actualiza el contenido del búfer.
     * @param deviceContext Referencia al contexto del dispositivo.
     * @param pDstResource Recurso de destino.
     * @param DstSubresource Subrecurso de destino.
     * @param pDstBox Cuadro delimitador de destino.
     * @param pSrcData Datos de origen.
     * @param SrcRowPitch Pitch de fila de origen.
     * @param SrcDepthPitch Pitch de profundidad de origen.
     */
    void
    update(DeviceContext& deviceContext, 
         ID3D11Resource* pDstResource,
         unsigned int DstSubresource,
         const D3D11_BOX* pDstBox,
         const void* pSrcData,
         unsigned int SrcRowPitch,
         unsigned int SrcDepthPitch);

    /**
     * @brief Establece el búfer en el pipeline de renderizado.
     * @param deviceContext Referencia al contexto del dispositivo.
     * @param StartSlot Slot inicial donde se colocará el búfer.
     * @param NumBuffers Número de búferes a establecer.
     * @param setPixelShader Indica si el búfer se debe establecer para el shader de píxeles.
     * @param format Formato del búfer.
     */
    void
    render(DeviceContext& deviceContext,
           unsigned int StartSlot,
           unsigned int NumBuffers,
           bool setPixelShader = false,
           DXGI_FORMAT format = DXGI_FORMAT_UNKNOWN);


    /**
     * @brief Libera los recursos utilizados por el búfer.
     */
    void 
    destroy();

    /**
     * @brief Crea un búfer DirectX con la descripción proporcionada.
     * @param device Referencia al dispositivo DirectX.
     * @param desc Descripción del búfer.
     * @param initData Datos iniciales para el búfer.
     * @return Código HRESULT que indica el éxito o fracaso de la creación.
     */
    HRESULT
    createBuffer(Device& device, 
                 D3D11_BUFFER_DESC& desc, 
                 D3D11_SUBRESOURCE_DATA* initData);


private:
    ID3D11Buffer* m_buffer = nullptr;
    unsigned int m_stride = 0;
    unsigned int m_offset = 0;
    unsigned int m_bindFlag = 0;
};