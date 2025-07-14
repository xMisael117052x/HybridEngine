#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;

/**
 * @brief Clase que gestiona las texturas para el renderizado en DirectX.
 */
class 
Texture {
public:
    /**
     * @brief Constructor por defecto.
     */
    Texture()  = default;
    
    /**
     * @brief Destructor por defecto.
     */
    ~Texture() = default;

    /**
     * @brief Inicializa una textura cargándola desde un archivo.
     * @param device Dispositivo DirectX.
     * @param textureName Nombre del archivo de textura.
     * @param extensionType Tipo de extensión del archivo.
     * @return Código HRESULT que indica el éxito o fracaso de la inicialización.
     */
    HRESULT
  init(Device device,
       const std::string & textureName,
       ExtensionType extensionType);

    /**
     * @brief Inicializa una textura vacía con las dimensiones y formato especificados.
     * @param device Dispositivo DirectX.
     * @param width Ancho de la textura en píxeles.
     * @param height Alto de la textura en píxeles.
     * @param Format Formato de los píxeles de la textura.
     * @param BindFlags Banderas que indican cómo se utilizará la textura.
     * @param sampleCount Número de muestras para antialiasing.
     * @param qualityLevels Niveles de calidad para antialiasing.
     * @return Código HRESULT que indica el éxito o fracaso de la inicialización.
     */
    HRESULT
  init(Device device,
       unsigned int width, 
       unsigned int height, 
       DXGI_FORMAT Format, 
       unsigned int BindFlags,
       unsigned int sampleCount = 1,
       unsigned int qualityLevels = 0);

    /**
     * @brief Inicializa una textura a partir de otra textura de referencia.
     * @param device Referencia al dispositivo DirectX.
     * @param textureRef Textura de referencia.
     * @param format Formato de la nueva textura.
     * @return Código HRESULT que indica el éxito o fracaso de la inicialización.
     */
    HRESULT 
  init(Device& device, Texture& textureRef, DXGI_FORMAT format);
	
    /**
     * @brief Actualiza la textura si es necesario.
     */
    void 
    update();
	
    /**
     * @brief Establece la textura en el contexto del dispositivo para su uso en shaders.
     * @param deviceContext Referencia al contexto del dispositivo.
     * @param StartSlot Slot inicial donde se colocará la vista de recurso del shader.
     * @param NumViews Número de vistas a establecer.
     */
    void 
  render(DeviceContext & deviceContext, unsigned int StartSlot, unsigned int NumViews);
	
    /**
     * @brief Libera los recursos utilizados por la textura.
     */
    void
    destroy();

public:
    ID3D11Texture2D* m_texture = nullptr;           ///< Textura 2D de DirectX
    ID3D11ShaderResourceView* m_textureFromImg;     ///< Vista de recurso de shader para la textura
};