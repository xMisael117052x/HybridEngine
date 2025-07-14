#include "Viewport.h"
#include "Window.h"
#include "DeviceContext.h"

/**
 * @brief Inicializa la ventanilla utilizando las dimensiones de una ventana.
 * @param window La ventana de la aplicación.
 * @return HRESULT El resultado de la operación.
 */
HRESULT 
Viewport::init(const Window& window) {
    if (!window.m_hWnd) {
        ERROR("Viewport", "init", "Window handle (m_hWnd) is nullptr");
        return E_POINTER;
    }
    if (window.m_width == 0 || window.m_height == 0) {
        ERROR("Viewport", "init", "Window dimensions are zero.");
        return E_INVALIDARG;
    }

    m_viewport.Width = static_cast<float>(window.m_width);
    m_viewport.Height = static_cast<float>(window.m_height);
    m_viewport.MinDepth = 0.0f;
    m_viewport.MaxDepth = 1.0f;
    m_viewport.TopLeftX = 0;
    m_viewport.TopLeftY = 0;

    return S_OK;
}

/**
 * @brief Inicializa la ventanilla con dimensiones específicas.
 * @param width El ancho de la ventanilla.
 * @param height El alto de la ventanilla.
 * @return HRESULT El resultado de la operación.
 */
HRESULT 
Viewport::init(unsigned int width, unsigned int height) {
    if (width == 0 || height == 0) {
        ERROR("Viewport", "init", "Window dimensions are zero.");
        return E_INVALIDARG;
    }

    m_viewport.Width = static_cast<float>(width);
    m_viewport.Height = static_cast<float>(height);
    m_viewport.MinDepth = 0.0f;
    m_viewport.MaxDepth = 1.0f;
    m_viewport.TopLeftX = 0;
    m_viewport.TopLeftY = 0;

    return S_OK;
}

/**
 * @brief Establece la ventanilla en el contexto del dispositivo.
 * @param deviceContext El contexto del dispositivo Direct3D.
 */
void
Viewport::render(DeviceContext& deviceContext) {
    deviceContext.RSSetViewports(1, &m_viewport);
}