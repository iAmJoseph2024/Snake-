#include "AssetAdmin.h"  

// Constructor por defecto de AssetMan
Engine::AssetMan::AssetMan() {}

// Destructor de AssetMan
Engine::AssetMan::~AssetMan() {}

// Funcion para añadir una textura al administrador de activos
void Engine::AssetMan::AnadirTextura(int id, const std::string& filePath, bool wantRepeated)
{
    auto texture = std::make_unique<sf::Texture>();  // Creamos una textura única

    // Cargamos la textura desde el archivo especificado
    if (texture->loadFromFile(filePath))
    {
        texture->setRepeated(wantRepeated);  // Configuramos si la textura debe repetirse
        mTexturas[id] = std::move(texture);  // Movemos la textura única al mapa de texturas
    }
}

// Método para añadir una fuente al administrador de activos
void Engine::AssetMan::AnadirFondo(int id, const std::string& filePath)
{
    auto font = std::make_unique<sf::Font>();  // Creamos una fuente única

    // Cargamos la fuente desde el archivo especificado
    if (font->loadFromFile(filePath))
    {
        mFondos[id] = std::move(font);  // Movemos la fuente única al mapa de fuentes
    }
}

// Funcion para obtener una textura por su identificador
const sf::Texture& Engine::AssetMan::GetTextura(int id) const
{
    return *(mTexturas.at(id).get());  // Devolvemos la textura referenciada por el id
}

// Funcion para obtener una fuente por su identificador
const sf::Font& Engine::AssetMan::GetFondo(int id) const
{
    return *(mFondos.at(id).get());  // Devolvemos la fuente referenciada por el id
}
