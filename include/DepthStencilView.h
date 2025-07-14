#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;
class Texture;

/**
 * @brief Clase que gestiona la vista de profundidad y estarcido para el renderizado en DirectX.
 */
class 
DepthStencilView {
public:
    /**
     * @brief Constructor por defecto.
     */
    DepthStencilView()  = default;
    
    /**
     * @brief Destructor por defecto.
     */
    ~DepthStencilView() = default;

    /**
     * @brief Inicializa la vista de profundidad y estarcido.
     * @param device Referencia al dispositivo DirectX.
     * @param depthStencil Textura de profundidad y estarcido asociada.
     * @param format Formato de la vista.
     * @return Código HRESULT que indica el éxito o fracaso de la inicialización.
     */
    HRESULT
    init(Device & device, Texture & depthStencil, DXGI_FORMAT format);
	
    /**
     * @brief Actualiza la vista de profundidad y estarcido si es necesario.
     */
    void 
    update();
	
    /**
     * @brief Establece la vista de profundidad y estarcido en el contexto del dispositivo.
     * @param deviceContext Referencia al contexto del dispositivo.
     */
    void 
    render(DeviceContext& deviceContext);
	
    /**
     * @brief Libera los recursos utilizados por la vista de profundidad y estarcido.
     */
    void 
    destroy();

public:
    ID3D11DepthStencilView* m_depthStencilView = nullptr;
};