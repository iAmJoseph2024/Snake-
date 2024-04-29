#include "AssetMan.h"

// Constructor por defecto de la clase AssetMan
Engine::AssetMan::AssetMan()
{
    // El constructor es generalizado y no requiere implementación adicional
}

// Destructor de la clase AssetMan
Engine::AssetMan::~AssetMan()
{

}

// Método para agregar una textura al AssetMan
void Engine::AssetMan::AddTexture(int id, const std::string& filePath, bool wantRepeated)
{
    // Creamos una textura utilizando std::make_unique
    auto texture = std::make_unique<sf::Texture>();

    // Intentamos cargar la textura desde el archivo especificado
    if (texture->loadFromFile(filePath))
    {
        // Establecemos si se quiere repetir la textura
        texture->setRepeated(wantRepeated);
        // Movemos la textura al mapa de texturas utilizando std::move
        m_textures[id] = std::move(texture);
    }
}

// Método para agregar una fuente al AssetMan
void Engine::AssetMan::AddFont(int id, const std::string& filePath)
{
    // Creamos una fuente utilizando std::make_unique
    auto font = std::make_unique<sf::Font>();

    // Intentamos cargar la fuente desde el archivo especificado
    if (font->loadFromFile(filePath))
    {
        // Movemos la fuente al mapa de fuentes utilizando std::move
        m_fonts[id] = std::move(font);
    }
}

// Método para obtener la variable texture constante a una textura del AssetMan
const sf::Texture& Engine::AssetMan::GetTexture(int id) const
{
    // Devolvemos la variable constante a la textura con el id especificado
    return *(m_textures.at(id).get());
}

// Método para obtener una variable font constante a una fuente del AssetMan
const sf::Font& Engine::AssetMan::GetFont(int id) const
{
    // Devolvemos la variable font constante a la fuente con el id especificado
    return *(m_fonts.at(id).get());
}
