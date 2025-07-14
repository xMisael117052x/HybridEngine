#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;
class Texture;
class DepthStencilView;

/**
 * @brief Clase que gestiona una vista de destino de renderizado en DirectX.
 */
class 
RenderTargetView {
public:
    /**
     * @brief Constructor por defecto.
     */
    RenderTargetView()  = default;
    
    /**
     * @brief Destructor por defecto.
     */
    ~RenderTargetView() = default;

    /**
     * @brief Inicializa la vista de destino de renderizado con un búfer posterior.
     * @param device Referencia al dispositivo DirectX.
     * @param backBuffer Textura del búfer posterior.
     * @param Format Formato de la vista.
     * @return Código HRESULT que indica el éxito o fracaso de la inicialización.
     */
    HRESULT
  init(Device& device, Texture &backBuffer, DXGI_FORMAT Format);
  
    /**
     * @brief Inicializa la vista de destino de renderizado con una textura personalizada.
     * @param device Referencia al dispositivo DirectX.
     * @param inTex Textura de entrada.
     * @param ViewDimension Dimensión de la vista.
     * @param Format Formato de la vista.
     * @return Código HRESULT que indica el éxito o fracaso de la inicialización.
     */
    HRESULT
    init(Device& device, 
         Texture& inTex, 
         D3D11_RTV_DIMENSION ViewDimension, 
         DXGI_FORMAT Format);

    /**
     * @brief Actualiza la vista de destino de renderizado si es necesario.
     */
    void 
    update();
  
    /**
     * @brief Establece y limpia la vista de destino de renderizado en el contexto del dispositivo.
     * @param deviceContext Referencia al contexto del dispositivo.
     * @param depthStencilView Vista de profundidad y estarcido asociada.
     * @param numViews Número de vistas a establecer.
     * @param ClearColor Color RGBA para limpiar la vista.
     */
    void 
    render(DeviceContext & deviceContext, 
           DepthStencilView & depthStencilView, 
           unsigned int numViews, 
           const float ClearColor[4]);
  
    /**
     * @brief Establece la vista de destino de renderizado en el contexto del dispositivo.
     * @param deviceContext Referencia al contexto del dispositivo.
     * @param numViews Número de vistas a establecer.
     */
    void 
    render(DeviceContext & deviceContext, 
           unsigned int numViews);
  
    /**
     * @brief Libera los recursos utilizados por la vista de destino de renderizado.
     */
    void 
    destroy();

private:
    ID3D11RenderTargetView* m_renderTargetView = nullptr;
};