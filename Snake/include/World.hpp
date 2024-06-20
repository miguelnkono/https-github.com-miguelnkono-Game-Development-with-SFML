#ifndef WORLD_HPP
#define WORLD_HPP

#include "Snake.hpp"

class World
{
    public:
        /** Default constructor */
        World(sf::Vector2u l_windSize);
        /** Default destructor */
        ~World();

        int GetBlockSize();
        void RespawnApple();
        void Update(Snake& l_player);
        void Render(sf::RenderWindow& l_window);

    protected:

    private:
        sf::Vector2u m_windowSize;
        sf::Vector2i m_item;
        int m_blockSize;

        sf::CircleShape m_appleShape;
        sf::RectangleShape m_bounds[4];
};

#endif // WORLD_HPP
