#pragma once

#include <map>
#include <memory>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

namespace Engine
{
    class AssetMan
    {
    public:
        AssetMan();
        ~AssetMan();

        // A�adir una textura al administrador de activos
        void AnadirTextura(int id, const std::string& filePath, bool wantRepeated = false);

        // A�adir una fuente al administrador de activos
        void AnadirFondo(int id, const std::string& filePath);

        // Obtener una textura por su identificador
        const sf::Texture& GetTextura(int id) const;

        // Obtener una fuente por su identificador
        const sf::Font& GetFondo(int id) const;

    private:
        // Mapas para almacenar texturas y fuentes usando identificadores �nicos
        std::map<int, std::unique_ptr<sf::Texture>> mTexturas;
        std::map<int, std::unique_ptr<sf::Font>> mFondos;
    };
}
