#pragma once

#include "Prerequisites.h"
#include "Window.h"
#include "Device.h"
#include "SwapChain.h"
#include "DeviceContext.h"
#include "Texture.h"
#include "RenderTargetView.h"
#include "DepthStencilView.h"
#include "Viewport.h"
#include "InputLayout.h"
#include "ShaderProgram.h"
#include "Buffer.h"
#include "MeshComponent.h"
#include "BlendState.h"
#include "DepthStencilState.h"
#include "ModelLoader.h"
#include "UserInterface.h"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

/**
 * @brief Clase base de la aplicación que gestiona todo el ciclo de vida y componentes principales.
 */
class BaseApp {
public:
    /**
     * @brief Constructor por defecto.
     */
    BaseApp() = default;
    
    /**
     * @brief Destructor por defecto.
     */
    ~BaseApp() = default;

    /**
     * @brief Inicia y ejecuta el ciclo principal de la aplicación.
     * @param hInstance Instancia de la aplicación.
     * @param nCmdShow Indica cómo se muestra la ventana.
     * @return Código de salida de la aplicación.
     */
    int run(HINSTANCE hInstance, int nCmdShow);

private:
    /**
     * @brief Inicializa todos los componentes de la aplicación.
     * @param hInstance Instancia de la aplicación.
     * @param nCmdShow Indica cómo se muestra la ventana.
     * @return Código HRESULT que indica el éxito o fracaso de la inicialización.
     */
    HRESULT init(HINSTANCE hInstance, int nCmdShow);
    
    /**
     * @brief Actualiza la lógica de la aplicación en cada fotograma.
     */
    void update();
    
    /**
     * @brief Renderiza los gráficos de la aplicación en cada fotograma.
     */
    void render();
    
    /**
     * @brief Libera los recursos utilizados por la aplicación.
     */
    void destroy();

    /**
     * @brief Función de procesamiento de mensajes de la ventana.
     * @param hWnd Manejador de la ventana.
     * @param message Tipo de mensaje.
     * @param wParam Parámetro adicional específico del mensaje.
     * @param lParam Parámetro adicional específico del mensaje.
     * @return Resultado del procesamiento del mensaje.
     */
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
    // Componentes de la aplicación
    Window g_window;
    Device g_device;
    SwapChain g_swapChain;
    DeviceContext g_deviceContext;
    Texture g_backBuffer;
    RenderTargetView g_renderTargetView;
    Texture g_depthStencil;
    DepthStencilView g_depthStencilView;
    Viewport g_viewport;
    ShaderProgram g_shaderProgram;
    ShaderProgram g_shaderShadow;
    BlendState g_shadowBlendState;
    DepthStencilState g_shadowDepthStencilState;
    UserInterface g_userInterface;
    ModelLoader g_modelLoader;
    Buffer m_neverChanges;
    Buffer m_changeOnResize;
    Buffer m_vertexBuffer;
    Buffer m_indexBuffer;
    Buffer m_changeEveryFrame;
    Buffer m_constShadow;
    Buffer m_planeVertexBuffer;
    Buffer m_planeIndexBuffer;
    Buffer m_constPlane;
    ID3D11ShaderResourceView* g_pTextureRV = nullptr;
    ID3D11SamplerState* g_pSamplerLinear = nullptr;
    ID3D11DepthStencilState* g_pShadowDepthStencilState = nullptr;
    XMMATRIX g_World;
    XMMATRIX g_PlaneWorld;
    XMMATRIX g_View;
    XMMATRIX g_Projection;
    XMFLOAT4 g_vMeshColor;
    XMFLOAT4 g_LightPos;
    XMFLOAT3 g_ModelRotation;
    float g_ModelScale;
    MeshComponent cubeMesh;
    CBNeverChanges cbNeverChanges;
    CBChangeOnResize cbChangesOnResize;
    CBChangesEveryFrame cb;
    CBChangesEveryFrame cbShadow;
};
