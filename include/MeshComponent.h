#pragma once
#include "Prerequisites.h"

class DeviceContext;

/**
 * @brief Clase que representa un componente de malla para renderizado 3D.
 */
class
  MeshComponent  {
public:
    /**
     * @brief Constructor que inicializa los contadores de vértices e índices.
     */
    MeshComponent() : m_numVertex(0), m_numIndex(0) {}

    /**
     * @brief Destructor virtual por defecto.
     */
    virtual
    ~MeshComponent() = default;

    /**
     * @brief Actualiza el estado de la malla.
     * @param deltaTime Tiempo transcurrido desde la última actualización en segundos.
     */
    void
    update(float deltaTime)  {}

    /**
     * @brief Renderiza la malla utilizando el contexto del dispositivo proporcionado.
     * @param deviceContext Referencia al contexto del dispositivo para el renderizado.
     */
    void
    render(DeviceContext& deviceContext) {}
    
public:
    std::string m_name;             ///< Nombre de la malla
    std::vector<SimpleVertex> m_vertex;  ///< Vector de vértices de la malla
    std::vector<unsigned int> m_index;   ///< Vector de índices para definir la topología
    int m_numVertex;                ///< Número total de vértices
    int m_numIndex;                 ///< Número total de índices
};