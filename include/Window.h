#pragma once
#include "Prerequisites.h"

/**
 * @brief Clase que gestiona la ventana de la aplicación.
 */
class 
Window {
public:
    /**
     * @brief Constructor por defecto.
     */
    Window() = default;
    
    /**
     * @brief Destructor por defecto.
     */
    ~Window() = default;

    /**
     * @brief Inicializa la ventana de la aplicación.
     * @param hInstance Instancia de la aplicación.
     * @param nCmdShow Parámetro que indica cómo se mostrará la ventana.
     * @param wndproc Función de procesamiento de mensajes de la ventana.
     * @return Código HRESULT que indica el éxito o fracaso de la inicialización.
     */
    HRESULT
    init(HINSTANCE hInstance, int nCmdShow, WNDPROC wndproc);

    /**
     * @brief Actualiza el estado de la ventana.
     */
    void 
    update();
	
    /**
     * @brief Realiza operaciones de renderizado relacionadas con la ventana.
     */
    void 
    render();
	
    /**
     * @brief Libera los recursos utilizados por la ventana.
     */
    void 
    destroy();

public:
    HWND m_hWnd = nullptr;           ///< Manejador de la ventana
    unsigned int m_width;            ///< Ancho de la ventana en píxeles
    unsigned int m_height;           ///< Alto de la ventana en píxeles
private:
    HINSTANCE m_hInst = nullptr;     ///< Instancia de la aplicación
    RECT m_rect;                     ///< Rectángulo que define las dimensiones de la ventana
    std::string m_windowName = "Hybrid Engine";  ///< Título de la ventana
};