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

        void AnadirTextura (int id, const std::string& filePath, bool wantRepeated = false);
        void AnadirFondo(int id, const std::string& filePath);

        const sf::Texture& GetTextura(int id) const;
        const sf::Font& GetFondo(int id) const;

    private:
        std::map<int, std::unique_ptr<sf::Texture>> mTexturas;
        std::map<int, std::unique_ptr<sf::Font>> mFondos;
    };
}