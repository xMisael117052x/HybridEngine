#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;

/**
 * @brief Clase que gestiona el layout de entrada que define la estructura de los vértices para el shader.
 */
class 
InputLayout {
public:
    /**
     * @brief Constructor por defecto.
     */
    InputLayout()  = default;
    
    /**
     * @brief Destructor por defecto.
     */
    ~InputLayout() = default;

    /**
     * @brief Inicializa el layout de entrada.
     * @param device Referencia al dispositivo DirectX.
     * @param Layout Vector con la descripción de los elementos del layout.
     * @param VertexShaderData Blob con el código compilado del shader de vértices.
     * @return Código HRESULT que indica el éxito o fracaso de la inicialización.
     */
    HRESULT
  init(Device& device, 
       std::vector<D3D11_INPUT_ELEMENT_DESC>& Layout, 
       ID3DBlob* VertexShaderData);

    /**
     * @brief Actualiza el layout de entrada si es necesario.
     */
    void 
    update();
  
    /**
     * @brief Establece el layout de entrada en el contexto del dispositivo.
     * @param deviceContext Referencia al contexto del dispositivo.
     */
    void 
    render(DeviceContext& deviceContext);
  
    /**
     * @brief Libera los recursos utilizados por el layout de entrada.
     */
    void 
    destroy();

public:
    ID3D11InputLayout* m_inputLayout = nullptr;
};