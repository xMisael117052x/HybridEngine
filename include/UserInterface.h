#pragma once
#include "Prerequisites.h"
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include "imgui_internal.h"

/**
 * @brief Clase que gestiona la interfaz de usuario utilizando ImGui.
 */
class
    UserInterface {
public:
    /**
     * @brief Constructor por defecto.
     */
    UserInterface() = default;
    
    /**
     * @brief Destructor por defecto.
     */
    ~UserInterface() = default;

    /**
     * @brief Inicializa la interfaz de usuario.
     * @param window Puntero a la ventana donde se mostrará la interfaz.
     * @param device Puntero al dispositivo DirectX.
     * @param deviceContext Puntero al contexto del dispositivo DirectX.
     */
    void
    init(void* window, ID3D11Device* device, ID3D11DeviceContext* deviceContext);

    /**
     * @brief Actualiza la interfaz de usuario en cada fotograma.
     */
    void
    update();

    /**
     * @brief Renderiza la interfaz de usuario en cada fotograma.
     */
    void
    render();

    /**
     * @brief Libera los recursos utilizados por la interfaz de usuario.
     */
    void
    destroy();

    /**
     * @brief Crea un control para editar un vector de 3 componentes.
     * @param label Etiqueta del control.
     * @param values Puntero a los valores a editar.
     * @param resetValue Valor al que se restablecen los componentes al hacer clic en el botón de reinicio.
     * @param columnWidth Ancho de las columnas del control.
     */
    void
    vec3Control(std::string label, float* values, float resetValue = 0.0f, float columnWidth = 100.0f);

    /**
     * @brief Crea un control para editar un valor flotante.
     * @param label Etiqueta del control.
     * @param value Puntero al valor a editar.
     * @param resetValue Valor al que se restablece al hacer clic en el botón de reinicio.
     * @param columnWidth Ancho de las columnas del control.
     */
    void
    floatControl(const std::string& label, float* value, float resetValue = 0.0f, float columnWidth = 100.0f);

private:
};
