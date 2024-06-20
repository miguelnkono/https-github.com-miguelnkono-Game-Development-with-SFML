#ifndef GAME_HPP
#define GAME_HPP
#include "Window.hpp"

class Game
{
    public:
        /** Default constructor */
        Game();
        /** Default destructor */
        ~Game();

        void HandleInput();
        void Update();
        void Render();
        Window *GetWindow();

        /// Mushroom
        void MoveMushroom();

        /// Dealing with the time
        sf::Time GetElapsed();
        void RestartClock();


    protected:

    private:
        Window m_window; //!< Member variable "m_window"

        /// For the mushroom little game
        sf::Texture m_mushroomTexture;
        sf::Sprite m_mushroom;
        sf::Vector2i m_increment;

        /// Dealing with time
        sf::Clock m_clock;
        sf::Time m_elapsed;
};

#endif // GAME_HPP
