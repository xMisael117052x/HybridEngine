#include "Window.h"

/**
 * @brief Inicializa la ventana de la aplicación.
 * @param hInstance El manejador de la instancia de la aplicación.
 * @param nCmdShow El modo de visualización de la ventana.
 * @param wndproc El procedimiento de ventana.
 * @return HRESULT El resultado de la operación.
 */
HRESULT 
Window::init(HINSTANCE hInstance, int nCmdShow, WNDPROC wndproc) {
    m_hInst = hInstance;

    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = wndproc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = m_hInst;
    wcex.hIcon = LoadIcon(m_hInst, (LPCTSTR)IDI_TUTORIAL1);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = "TutorialWindowClass";
    wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_TUTORIAL1);

    if (!RegisterClassEx(&wcex)) {
        MessageBox(nullptr, "RegisterClassEx failed!", "Error", MB_OK);
        ERROR("Window", "init", "CHECK FOR RegisterClassEx");
        return E_FAIL;
    }

    RECT rc = { 0, 0, 1200, 1010 };
    m_rect = rc;

    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

    m_hWnd = CreateWindow("TutorialWindowClass", 
                          m_windowName.c_str(),
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, 
                          CW_USEDEFAULT, 
                          m_rect.right -  m_rect.left, 
                          m_rect.bottom - m_rect.top, 
                          nullptr, 
                          nullptr, 
                          hInstance,
                          nullptr);

    if (!m_hWnd) {
        MessageBox(nullptr, "CreateWindow failed!", "Error", MB_OK);
        ERROR("Window", "init", "CHECK FOR CreateWindow()");
        return E_FAIL;
    }

    ShowWindow(m_hWnd, nCmdShow);

    UpdateWindow(m_hWnd);

    GetClientRect(m_hWnd, &m_rect);
    m_width = m_rect.right - m_rect.left;
    m_height = m_rect.bottom - m_rect.top;
    return S_OK;
}

/**
 * @brief Función que actualiza el estado de la ventana.
 */
void
Window::update() {
}

/**
 * @brief Renderiza el contenido de la ventana.
 */
void 
Window::render() {
}

/**
 * @brief Libera los recursos de la ventana.
 */
void 
Window::destroy() {
}
