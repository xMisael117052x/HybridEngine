#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;
class Window;
class Texture;

/**
 * @brief Clase que gestiona la cadena de intercambio (swap chain) para presentar los frames renderizados en pantalla.
 */
class 
SwapChain {
public:
    /**
     * @brief Constructor por defecto.
     */
    SwapChain()  = default;
    
    /**
     * @brief Destructor por defecto.
     */
    ~SwapChain() = default;

    /**
     * @brief Inicializa la cadena de intercambio.
     * @param device Referencia al dispositivo DirectX.
     * @param deviceContext Referencia al contexto del dispositivo.
     * @param backBuffer Puntero donde se almacenará el búfer posterior.
     * @param window Ventana donde se presentarán los frames.
     * @return Código HRESULT que indica el éxito o fracaso de la inicialización.
     */
    HRESULT
    init(Device & device, 
         DeviceContext & deviceContext, 
         ID3D11Texture2D** backBuffer, 
         Window window);

    /**
     * @brief Actualiza la cadena de intercambio si es necesario.
     */
    void 
    update();
  
    /**
     * @brief Realiza operaciones de renderizado si es necesario.
     */
    void 
    render();
  
    /**
     * @brief Libera los recursos utilizados por la cadena de intercambio.
     */
    void 
    destroy();
    
    /**
     * @brief Presenta el frame actual en pantalla.
     */
    void
    present();

public:
    IDXGISwapChain* m_swapChain = nullptr;        ///< Puntero a la interfaz de la cadena de intercambio
    D3D_DRIVER_TYPE m_driverType = D3D_DRIVER_TYPE_NULL;  ///< Tipo de controlador DirectX
private:
    D3D_FEATURE_LEVEL m_featureLevel = D3D_FEATURE_LEVEL_11_0;  ///< Nivel de características de DirectX

    unsigned int m_sampleCount;    ///< Número de muestras para antialiasing
    unsigned int m_qualityLevels;  ///< Niveles de calidad disponibles

    IDXGIDevice* m_dxgiDevice = nullptr;    ///< Interfaz DXGI del dispositivo
    IDXGIAdapter* m_dxgiAdapter = nullptr;  ///< Adaptador gráfico
    IDXGIFactory* m_dxgiFactory = nullptr;  ///< Fábrica DXGI para crear la cadena de intercambio
};
