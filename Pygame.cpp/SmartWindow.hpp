#pragma once

#include <SDL_video.h>

class SmartWindow
{
    SDL_Window* m_window;
    void cleanup() const;

  public:
    SmartWindow(const char* title, int x, int y, int w, int h, Uint32 flags);
    ~SmartWindow();
    SmartWindow(const SmartWindow&) = delete;
    SmartWindow& operator=(const SmartWindow&) = delete;
    SmartWindow(SmartWindow&& other) noexcept;
    SmartWindow& operator=(SmartWindow&& other) noexcept;

    SDL_Window* get() const;
};
