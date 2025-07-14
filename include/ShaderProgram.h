#pragma once
#include "Prerequisites.h"
#include "InputLayout.h"

class Device;
class DeviceContext;

/**
 * @brief Clase que gestiona un programa de shader que incluye shaders de vértices y píxeles.
 */
class 
ShaderProgram {
public:
    /**
     * @brief Constructor por defecto.
     */
    ShaderProgram ()  = default;
    
    /**
     * @brief Destructor por defecto.
     */
    ~ShaderProgram () = default;

    /**
     * @brief Inicializa el programa de shader cargando los shaders desde un archivo.
     * @param device Referencia al dispositivo DirectX.
     * @param fileName Nombre del archivo que contiene el código del shader.
     * @param Layout Vector con la descripción de los elementos del layout de entrada.
     * @return Código HRESULT que indica el éxito o fracaso de la inicialización.
     */
    HRESULT 
    init(Device& device, 
         const std::string& fileName, 
         std::vector<D3D11_INPUT_ELEMENT_DESC> Layout);

    /**
     * @brief Actualiza el programa de shader si es necesario.
     */
    void 
    update();
  
    /**
     * @brief Establece el programa de shader completo en el contexto del dispositivo.
     * @param deviceContext Referencia al contexto del dispositivo.
     */
    void 
    render(DeviceContext& deviceContext);
  
    /**
     * @brief Establece un tipo específico de shader en el contexto del dispositivo.
     * @param deviceContext Referencia al contexto del dispositivo.
     * @param type Tipo de shader a establecer (vértice o píxel).
     */
    void 
    render(DeviceContext& deviceContext, ShaderType type);
  
    /**
     * @brief Libera los recursos utilizados por el programa de shader.
     */
    void 
    destroy();

    /**
     * @brief Crea el layout de entrada para el shader de vértices.
     * @param device Referencia al dispositivo DirectX.
     * @param Layout Vector con la descripción de los elementos del layout.
     * @return Código HRESULT que indica el éxito o fracaso de la creación.
     */
    HRESULT
    CreateInputLayout(Device & device, std::vector<D3D11_INPUT_ELEMENT_DESC> Layout);

    /**
     * @brief Crea un shader del tipo especificado.
     * @param device Referencia al dispositivo DirectX.
     * @param type Tipo de shader a crear (vértice o píxel).
     * @return Código HRESULT que indica el éxito o fracaso de la creación.
     */
    HRESULT
    CreateShader(Device & device, ShaderType type);
  
    /**
     * @brief Crea un shader del tipo especificado cargándolo desde un archivo.
     * @param device Referencia al dispositivo DirectX.
     * @param type Tipo de shader a crear (vértice o píxel).
     * @param fileName Nombre del archivo que contiene el código del shader.
     * @return Código HRESULT que indica el éxito o fracaso de la creación.
     */
    HRESULT
    CreateShader(Device & device, ShaderType type, const std::string& fileName);

    /**
     * @brief Compila un shader desde un archivo.
     * @param szFileName Nombre del archivo que contiene el código del shader.
     * @param szEntryPoint Punto de entrada del shader.
     * @param szShaderModel Modelo de shader a utilizar.
     * @param ppBlobOut Puntero donde se almacenará el blob compilado.
     * @return Código HRESULT que indica el éxito o fracaso de la compilación.
     */
    HRESULT 
    CompileShaderFromFile(char* szFileName, 
                          LPCSTR szEntryPoint, 
                          LPCSTR szShaderModel, 
                          ID3DBlob** ppBlobOut);

public:
    ID3D11VertexShader* m_VertexShader = nullptr;  ///< Shader de vértices
    ID3D11PixelShader* m_PixelShader = nullptr;    ///< Shader de píxeles
    InputLayout m_inputLayout;                     ///< Layout de entrada para el shader de vértices
private:
    std::string m_shaderFileName;                  ///< Nombre del archivo del shader
    ID3DBlob* m_vertexShaderData = nullptr;        ///< Datos compilados del shader de vértices
    ID3DBlob* m_pixelShaderData = nullptr;         ///< Datos compilados del shader de píxeles
};