#include "Game.hpp"

/// Mushroom
Game::Game() : m_window("chapter-2", sf::Vector2u(800, 600)),
                m_snake(m_world.GetBlockSize()), m_world(sf::Vector2u(800, 600))
{
    /// Mushroom
    /*m_mushroomTexture.loadFromFile("C:\\Users\\Nkono Ndeme Miguel\\Desktop\\SFML-JourneyLearn\\GameDevelopment\\Others\\mushroom.png");
    m_mushroom.setTexture(m_mushroomTexture);
    m_increment = sf::Vector2i(400, 400);
    */

    m_textbox.Setup(5, 14, 400, sf::Vector2f(225, 0));
    m_textbox.Add("Seeded  random number generator with: " + std::to_string(time(NULL)));
}

Game::~Game() {}

void Game::HandleInput() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
       && m_snake.GetDirection() != Direction::Down)
    {
        m_snake.SetDirection(Direction::Up);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
              && m_snake.GetDirection() != Direction::Up)
    {
        m_snake.SetDirection(Direction::Down);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
              && m_snake.GetDirection() != Direction::Right)
    {
        m_snake.SetDirection(Direction::Left);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
              && m_snake.GetDirection() != Direction::Left)
    {
        m_snake.SetDirection(Direction::Right);
    }
}

void Game::Update()
{
    m_window.Update();

    /// Mushroom
    ///MoveMushroom();

    /// Snake Game
    float timestep = 1.0f / m_snake.GetSpeed();

    if(m_elapsed.asSeconds() >= timestep)
    {
        m_snake.Tick();
        m_world.Update(m_snake);
        m_elapsed -= sf::seconds(timestep);
        if(m_snake.HasLost())
        {
            m_snake.Reset();
        }
    }
}

/// Mushroom
/*void Game::MoveMushroom()
{
    sf::Vector2u l_windSize = m_window.GetWindowSize();
    sf::Vector2u l_textSize = m_mushroomTexture.getSize();

    /// Finding the time elapsed
    float fElapsed = m_elapsed.asSeconds();

    /// Checking for edges
    if ((m_mushroom.getPosition().x > (l_windSize.x - l_textSize.x) && m_increment.x > 0) ||
        (m_mushroom.getPosition().x < 0 && m_increment.x < 0)) {
            m_increment.x = -m_increment.x;
    }
    if ((m_mushroom.getPosition().y > (l_windSize.y - l_textSize.y) && m_increment.y > 0) ||
        (m_mushroom.getPosition().y < 0 && m_increment.y < 0)) {
            m_increment.y = -m_increment.y;
    }


    m_mushroom.setPosition(m_mushroom.getPosition().x + m_increment.x*fElapsed,
                            m_mushroom.getPosition().y + m_increment.y*fElapsed);
}
*/

void Game::Render()
{
    m_window.BeginDraw();

    /// Mushroom
    ///m_window.Draw(m_mushroom);

    /// Snake Game
    m_world.Render(*m_window.GetRenderWindow());
    m_snake.Render(*m_window.GetRenderWindow());

    /// Text box thing.
    m_textbox.Render(*m_window.GetRenderWindow());

    m_window.EndDraw();
}

Window* Game::GetWindow()
{
    return &m_window;
}

sf::Time Game::GetElapsed()
{
    return m_clock.getElapsedTime();
}

void Game::RestartClock()
{
    m_elapsed += m_clock.restart();
}
