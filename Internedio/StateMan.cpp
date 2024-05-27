#include "StateMan.h"

// Constructor de la clase StateMan
Engine::StateMan::StateMan() : m_add(false), m_replace(false), m_remove(false) {
    // Inicializamos las variables m_add, m_replace y m_remove a false
}

// Destructor de la clase StateMan
Engine::StateMan::~StateMan() {
    // El destructor es generalizado y no requiere implementación adicional
}

// Método para agregar un nuevo estado al StateMan
void Engine::StateMan::Add(std::unique_ptr<State> toAdd, bool replace) {
    // Establecemos m_add a true para indicar que se debe agregar un nuevo estado
    m_add = true;
    // Movemos el puntero único toAdd al miembro m_newState
    m_newState = std::move(toAdd);
    // Establecemos m_replace al valor proporcionado como argumento
    m_replace = replace;
}

// Método para eliminar el estado actual del StateMan
void Engine::StateMan::PopCurrent() {
    // Establecemos m_remove a true para indicar que se debe eliminar el estado actual
    m_remove = true;
}

// Método para procesar los cambios de estado pendientes
void Engine::StateMan::ProcessStateChange() {
    if (m_remove && (!m_stateStack.empty())) {
        // Eliminamos el estado actual del stack
        m_stateStack.pop();

        // Si el stack aún contiene estados, llamamos al método Start() del nuevo estado actual
        if (!m_stateStack.empty()) {
            m_stateStack.top()->Start();
        }
        // Reiniciamos la variable m_remove a false
        m_remove = false;
    }

    // Si se solicita agregar un nuevo estado
    if (m_add) {
        // Si se solicita reemplazar el estado actual y el stack no está vacío
        if (m_replace && (!m_stateStack.empty())) {
            // Eliminamos el estado actual del stack
            m_stateStack.pop();
            // Reiniciamos la variable m_replace a false
            m_replace = false;
        }

        // Si el stack no está vacío, llamamos al método Pause() del estado actual
        if (!m_stateStack.empty()) {
            m_stateStack.top()->Pause();
        }

        // Agregamos el nuevo estado del stack y llamamos a sus funciones Init() y Start()
        m_stateStack.push(std::move(m_newState));
        m_stateStack.top()->Init();
        m_stateStack.top()->Start();
        // Reiniciamos la variable m_add a false
        m_add = false;
    }
}

// Método para obtener una referencia al estado actual del stack de estados
std::unique_ptr<Engine::State>& Engine::StateMan::GetCurrent() {
    // Devolvemos la variable al estado en la cima del stack
    return m_stateStack.top();
}
