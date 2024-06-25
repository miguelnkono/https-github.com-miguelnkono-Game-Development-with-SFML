#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include <vector>
#include <unordered_map>
#include <functional>
#include <SFML/Graphics.hpp>

/// Enumerations of the different type of events.
enum class EventType {
    KeyDown         = sf::Event::KeyPressed,
    Key             = sf::Event::KeyReleased,
    MButtonDown     = sf::Event::MouseButtonPressed,
    MButtonUp       = sf::Event::MouseButtonReleased,
    MouseWheel      = sf::Event::MouseWheelMoved,
    WindowResized   = sf::Event::Resized,
    GainedFocus     = sf::Event::GainedFocus,
    LostFocus       = sf::Event::LostFocus,
    MouseEntered    = sf::Event::MouseEntered,
    MouseLeft       = sf::Event::MouseLeft,
    Closed          = sf::Event::Closed,
    TextEntered     = sf::Event::TextEntered,
    Keyboard        = sf::Event::Count + 1, Mouse, Joystick
};

/// Structure to store the informations about the keys been pressed.
struct EventInfo {
    EventInfo() { m_code = 0; }
    EventInfo(int l_event) { m_code = l_event; }

    union {
        int m_code;
    };
};

/// Data type to hold the information on the event.
using Events = std::vector<std::pair<EventType, EventInfo>>;

/// Details about the event actually handling.
struct EventDetails {
    EventDetails(std::string& l_bindName)
        : m_name(l_bindName)
    {
        Clear();
    }

    std::string m_name;
    sf::Vector2i m_size;
    sf::Uint32 m_textEntered;
    sf::Vector2i m_mouse;
    int m_keyCode;      /// Single key code.

    void Clear()
    {
        m_size = sf::Vector2i(0, 0);
        m_textEntered = 0;
        m_mouse = sf::Vector2i(0, 0);
        m_keyCode = -1;
    }
};

/// Structure that is going  to hold all the event infos.
struct Binding {
    Binding(std::string l_name)
        : m_name(l_name), m_details(l_name), c(0) {}

    void BindEvent(EventType l_type, EventInfo l_info = EventInfo())
    {
        m_event.emplace_back(l_type, l_info);
    }

    Events m_event;
    std::string m_name;
    int c;      /// Count of events that are "happening".

    EventDetails m_details;
} ;

/// Data structure to hold all the bindings.
using Bindings = std::unordered_map<std::string, Binding*>;

/// Type of the callback container.
using Callbacks = std::unordered_map<std::string, std::function<void(EventDetails*)>>;


/// The EventManager class.
class EventManager {
public:
    EventManager();
    ~EventManager();

    bool AddBinding(Binding* l_binding);
    bool RemoveBinding(std::string l_name);
    void SetFocus(const bool& l_focus);

    /// The callback.
    template<class T>
    bool AddCallback(const std::string& l_name, void(T::*l_func) (EventDetails*), T* l_instance)
    {
        auto temp = std::bind(l_func, l_instance, std::placeholders::_1);
        return m_callbacks.emplace(l_name, temp).second;
    }

    void RemoveCallback(const std::string& l_name)
    {
        m_callbacks.erase(l_name);
    }

    void HandleEvent(sf::Event& l_event);
    void Update();

    sf::Vector2i GetMousePos(sf::RenderWindow* l_wind = nullptr)
    {
        return (l_wind ? sf::Mouse::getPosition(*l_wind) : sf::Mouse::getPosition());
    }

private:
    void LoadBindings();

    Bindings m_bindings;
    Callbacks m_callbacks;
    bool m_hasFocus;
};

#endif // EVENTMANAGER_HPP
