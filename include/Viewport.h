#pragma once
#include "Prerequisites.h"
class Window;
class DeviceContext;

/**
 * @brief Clase que gestiona el viewport (área de visualización) para el renderizado en DirectX.
 */
class 
Viewport {
public:
    /**
     * @brief Constructor por defecto.
     */
    Viewport() = default;
    
    /**
     * @brief Destructor por defecto.
     */
    ~Viewport() = default;

    /**
     * @brief Inicializa el viewport basándose en las dimensiones de una ventana.
     * @param window Referencia a la ventana que define las dimensiones.
     * @return Código HRESULT que indica el éxito o fracaso de la inicialización.
     */
    HRESULT
  init(const Window & window);
  
    /**
     * @brief Inicializa el viewport con dimensiones específicas.
     * @param width Ancho del viewport en píxeles.
     * @param height Alto del viewport en píxeles.
     * @return Código HRESULT que indica el éxito o fracaso de la inicialización.
     */
    HRESULT
    init(unsigned int width, unsigned int height);

    /**
     * @brief Actualiza el viewport si es necesario.
     */
    void 
    update();
  
    /**
     * @brief Establece el viewport en el contexto del dispositivo.
     * @param deviceContext Referencia al contexto del dispositivo.
     */
    void 
    render(DeviceContext& deviceContext);
  
    /**
     * @brief Libera los recursos utilizados por el viewport.
     */
    void 
    destroy();

public:
    D3D11_VIEWPORT m_viewport;  ///< Estructura que define el viewport de DirectX
};