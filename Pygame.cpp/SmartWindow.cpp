#include "SmartWindow.hpp"

#include "MySDL.hpp"

void SmartWindow::cleanup() const
{
    if (m_window != nullptr)
    {
        SDL_DestroyWindow(m_window);
    }
}

SmartWindow::SmartWindow(const char* title, int x, int y, int w, int h, Uint32 flags)
    : m_window(mysdl::CheckPointer(SDL_CreateWindow(title, x, y, w, h, flags)))
{
}

SmartWindow::~SmartWindow()
{
    cleanup();
}

SmartWindow::SmartWindow(SmartWindow&& other) noexcept : m_window(other.m_window)
{
    other.m_window = nullptr;
}

SmartWindow& SmartWindow::operator=(SmartWindow&& other) noexcept
{
    if (&other != this)
    {
        cleanup();
        m_window = other.m_window;
        other.m_window = nullptr;
    }

    return *this;
}

SDL_Window* SmartWindow::get() const
{
    return m_window;
}
