#pragma once
#include "OBJ_Loader.h"
#include "Prerequisites.h"

class MeshComponent;

/**
 * @brief Clase responsable de cargar modelos 3D desde archivos externos.
 */
class ModelLoader {
public:
    /**
     * @brief Constructor por defecto.
     */
    ModelLoader() = default;
    
    /**
     * @brief Destructor por defecto.
     */
    ~ModelLoader() = default;

    /**
     * @brief Inicializa el cargador de modelos.
     */
    void
    init();

    /**
     * @brief Actualiza el estado del cargador de modelos si es necesario.
     */
    void
    update();

    /**
     * @brief Realiza operaciones de renderizado si es necesario.
     */
    void
    render();

    /**
     * @brief Libera los recursos utilizados por el cargador de modelos.
     */
    void
    destroy();

    /**
     * @brief Carga un modelo desde un archivo.
     * @param filename Ruta del archivo a cargar.
     * @return Un componente de malla que representa el modelo cargado.
     */
    MeshComponent
    Load(const std::string& filename);
};
