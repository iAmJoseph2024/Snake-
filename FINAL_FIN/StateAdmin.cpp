#include "StateAdmin.h"

// Constructor de la clase StateMan
Engine::StateMan::StateMan() : m_add(false), m_replace(false), m_remove(false), m_removeAll(false) {}

// Destructor de la clase StateMan
Engine::StateMan::~StateMan() {}

// Funcion para agregar un nuevo estado
void Engine::StateMan::Add(std::unique_ptr<State> toAdd, bool replace)
{
    m_add = true; // Marca que se debe agregar un nuevo estado
    m_newState = std::move(toAdd); // Mueve el nuevo estado al miembro m_newState
    m_replace = replace; // Determina si el nuevo estado reemplazará al actual
}

// Funcion para eliminar el estado actual
void Engine::StateMan::PopCurrent()
{
    m_remove = true; // Marca que se debe eliminar el estado actual
}

// Método para eliminar todos los estados
void Engine::StateMan::PopAll()
{
    m_removeAll = true; // Marca que se deben eliminar todos los estados
    m_remove = false; // Asegura que no se procese una eliminación individual
}

// Funcion para procesar los cambios de estado
void Engine::StateMan::ProcessStateChange()
{
    // Elimina todos los estados si está marcado
    if (m_removeAll)
    {
        while (!m_stateStack.empty())
        {
            m_stateStack.pop();
        }
        m_removeAll = false; 
    }
    // Elimina el estado actual si está marcado
    else if (m_remove && (!m_stateStack.empty()))
    {
        m_stateStack.pop();

        // Si todavía hay estados en el stack, reanuda el estado superior
        if (!m_stateStack.empty())
        {
            m_stateStack.top()->Empezar();
        }

        m_remove = false; 
    }

    // Agrega un nuevo estado si está marcado
    if (m_add)
    {
        // Reemplaza el estado actual si está marcado
        if (m_replace && (!m_stateStack.empty()))
        {
            m_stateStack.pop();
            m_replace = false; 
        }

        // Pausa el estado actual si el stack no está vacío
        if (!m_stateStack.empty())
        {
            m_stateStack.top()->Pausa();
        }

        // Agrega el nuevo estado a el stack y lo inicializa
        m_stateStack.push(std::move(m_newState));
        m_stateStack.top()->Init();
        m_stateStack.top()->Empezar();
        m_add = false; 
    }
}

// Funcion para obtener el estado actual
std::unique_ptr<Engine::State>& Engine::StateMan::GetCurrent()
{
    return m_stateStack.top();
}

// Funcion para verificar si el stack de estados está vacío
bool Engine::StateMan::Vacio() const
{
    return m_stateStack.empty();
}
