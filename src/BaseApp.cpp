#include "BaseApp.h"

/**
 * @brief Inicializa la aplicación base.
 * @return HRESULT El resultado de la operación.
 */
HRESULT BaseApp::init()
{
    return E_NOTIMPL;
}

/**
 * @brief Función que actualiza el estado de la aplicación.
 */
void 
BaseApp::update() {

}

/**
 * @brief Renderiza la escena de la aplicación.
 */
void 
BaseApp::render() {

}

/**
 * @brief Libera los recursos de la aplicación.
 */
void 
BaseApp::destroy() {

}

/**
 * @brief Ejecuta el bucle principal de la aplicación.
 * @param hInstance El manejador de la instancia de la aplicación.
 * @param hPrevInstance El manejador de la instancia previa de la aplicación.
 * @param lpCmdLine La línea de comandos.
 * @param nCmdShow El modo de visualización de la ventana.
 * @param wndproc El procedimiento de ventana.
 * @return int El código de salida de la aplicación.
 */
int
BaseApp::run(HINSTANCE hInstance,
                         HINSTANCE hPrevInstance,
                         LPWSTR lpCmdLine,
                         int nCmdShow,
                         WNDPROC wndproc) {

    return 0;
}