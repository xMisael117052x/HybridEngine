#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;

/**
 * @brief Clase que gestiona el estado de mezcla (blend) para renderizado en DirectX.
 */
class
BlendState {
public:
    /**
     * @brief Constructor por defecto.
     */
    BlendState() = default;
    
    /**
     * @brief Destructor por defecto.
     */
    ~BlendState() = default;

    /**
     * @brief Inicializa el estado de mezcla.
     * @param device Referencia al dispositivo DirectX.
     * @return Código HRESULT que indica el éxito o fracaso de la inicialización.
     */
    HRESULT
    init(Device& device);

    /**
     * @brief Actualiza el estado de mezcla si es necesario.
     */
    void
    update() {
    };

    /**
     * @brief Aplica el estado de mezcla al contexto del dispositivo.
     * @param deviceContext Referencia al contexto del dispositivo.
     * @param blendFactor Factor de mezcla opcional.
     * @param sampleMask Máscara de muestreo opcional.
     * @param reset Indica si se debe restablecer el estado de mezcla.
     */
    void
    render(DeviceContext& deviceContext,
           float* blendFactor = nullptr,
           unsigned int sampleMask = 0xffffffff,
           bool reset = false);

    /**
     * @brief Libera los recursos utilizados por el estado de mezcla.
     */
    void
    destroy();

private:
    ID3D11BlendState* m_blendState = nullptr;
};
