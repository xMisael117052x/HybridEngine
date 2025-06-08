#include "DeviceContext.h"

/**
 * @brief Establece las ventanillas de rasterización.
 * @param NumViewports El número de ventanillas a establecer.
 * @param pViewports Un array de descripciones de ventanillas.
 */
void 
DeviceContext::RSSetViewports(unsigned int NumViewports, 
                                                            const D3D11_VIEWPORT* pViewports) {
    if (NumViewports > 0 && pViewports != nullptr) {
        ERROR("DeviceContext", "RSSetViewports", "pViewports is nullptr");
    }
    m_deviceContext->RSSetViewports(NumViewports, pViewports);
}

/**
 * @brief Limpia la vista de plantilla de profundidad.
 * @param pDepthStencilView Puntero a la vista de plantilla de profundidad.
 * @param ClearFlags Indicadores que especifican qué partes de la vista de plantilla de profundidad limpiar.
 * @param Depth El valor de profundidad con el que limpiar.
 * @param Stencil El valor de plantilla con el que limpiar.
 */
void 
DeviceContext::ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView, 
                                                                         unsigned int ClearFlags, 
                                                                         float Depth, 
                                                                         UINT8 Stencil) {
    // Implementación faltante                                                                         
}

/**
 * @brief Limpia la vista de destino de renderizado.
 * @param pRenderTargetView Puntero a la vista de destino de renderizado.
 * @param ColorRGBA El color con el que limpiar la vista de destino de renderizado.
 */
void 
DeviceContext::ClearRenderTargetView(ID3D11RenderTargetView* pRenderTargetView, 
                                                                         const float ColorRGBA[4]) {
    // Implementación faltante
}