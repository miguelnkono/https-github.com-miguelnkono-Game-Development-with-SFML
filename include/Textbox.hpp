#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using MessageContainer = std::vector<std::string>;

class Textbox
{
    public:
        /** Default constructor */
        Textbox();
        /** Default destructor */
        ~Textbox();
        Textbox(int l_visible, int charSize, int l_width, sf::Vector2f l_screenPos);

        void Setup(int l_visible, int charSize, int l_width, sf::Vector2f l_screenPos);
        void Add(std::string l_message);
        void Clear();
        void Render(sf::RenderWindow& l_wind);

    protected:

    private:
        MessageContainer m_messages;
        int m_numVisible;

        sf::RectangleShape m_backdrop;
        sf::Font m_font;
        sf::Text m_content;

};

#endif // TEXTBOX_HPP
