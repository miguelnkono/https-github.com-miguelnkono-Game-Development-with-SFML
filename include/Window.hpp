#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <SFML/Graphics.hpp>

class Window
{
    public:
        /** Default constructor */
        Window();
        /** Default destructor */
        ~Window();
        Window(const std::string& l_title ,const sf::Vector2u& l_size);

        void BeginDraw();
        void EndDraw();
        void Update();
        bool IsDone();
        bool IsFullscreen();
        void Draw(sf::Drawable& l_drawable);
        sf::Vector2u GetWindowSize();
        void ToggleFullscreen();

    private:
        void Setup(const std::string& l_title, const sf::Vector2u& l_size);
        void Destroy();
        void Create();

        sf::RenderWindow m_window; //!< Member variable "m_window"
        sf::Vector2u m_windowSize; //!< Member variable "m_windowSize"
        std::string m_windowTitle; //!< Member variable "m_windowTitle"
        bool m_isDone; //!< Member variable "m_isDone"
        bool m_isFullscreen; //!< Member variable "m_isFullscreen"
};

#endif // WINDOW_H
