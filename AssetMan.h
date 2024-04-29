#pragma once

#include <map> // Incluimos la libreria para std::map
#include <memory> // Incluimos la libreria para std::unique_ptr
#include <string> // Incluimos la libreria para std::string

#include <SFML/Graphics/Texture.hpp> // Incluimos la libreria para sf::Texture
#include <SFML/Graphics/Font.hpp> // Incluimos la libreria para sf::Font

namespace Engine {
    // Definimos una clase llamada AssetMan en el namespace Engine
    class AssetMan {
    private:
        // Mapas que almacenan punteros únicos a objetos de tipo sf::Texture y sf::Font
        std::map<int, std::unique_ptr<sf::Texture>> m_textures;
        std::map<int, std::unique_ptr<sf::Font>> m_fonts;

    public:
        // Constructor por defecto y destructor de la clase AssetMan
        AssetMan();
        ~AssetMan();

        // Agrega una textura al mapa de texturas
        void AddTexture(int id, const std::string& filePath, bool wantRepeated = false);

        // Agrega una fuente al mapa de fuentes
        void AddFont(int id, const std::string& filePath);

        // Obtiene una referencia constante a una textura del mapa de texturas
        const sf::Texture& GetTexture(int id) const;

        // Obtiene una referencia constante a una fuente del mapa de fuentes
        const sf::Font& GetFont(int id) const;
    };
} // namespace Engine
