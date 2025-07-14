#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;

/**
 * @brief Clase que gestiona el estado de profundidad y estarcido (depth-stencil) para el renderizado en DirectX.
 */
class
DepthStencilState {
public:
    /**
     * @brief Constructor por defecto.
     */
    DepthStencilState() = default;
    
    /**
     * @brief Destructor por defecto.
     */
    ~DepthStencilState() = default;

    /**
     * @brief Inicializa el estado de profundidad y estarcido.
     * @param device Referencia al dispositivo DirectX.
     * @param enableDepth Indica si se debe habilitar la prueba de profundidad.
     * @param enableStencil Indica si se debe habilitar la prueba de estarcido.
     * @return Código HRESULT que indica el éxito o fracaso de la inicialización.
     */
    HRESULT
    init(Device& device, bool enableDepth = true, bool enableStencil = false);

    /**
     * @brief Actualiza el estado de profundidad y estarcido si es necesario.
     */
    void
    update();

    /**
     * @brief Aplica el estado de profundidad y estarcido al contexto del dispositivo.
     * @param deviceContext Referencia al contexto del dispositivo.
     * @param stencilRef Valor de referencia para la prueba de estarcido.
     * @param reset Indica si se debe restablecer el estado de profundidad y estarcido.
     */
    void
    render(DeviceContext& deviceContext, unsigned int stencilRef = 0, bool reset = false);

    /**
     * @brief Libera los recursos utilizados por el estado de profundidad y estarcido.
     */
    void
    destroy();
    
private:
    ID3D11DepthStencilState* m_depthStencilState = nullptr;
};
