// Pygame.cpp.cpp : Defines the entry point for the application.
//

#include "GraphicsContext.hpp"
#include "MySDL.hpp"
#include "SmartRenderer.hpp"
#include "SmartSurface.hpp"
#include "SmartTexture.hpp"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

int main(int /*argc*/, char** /*argv*/)
{
    GraphicsContext gcon;
    const SmartWindow window{"Pygame.cpp", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800,
                             400,          SDL_WINDOW_ALLOW_HIGHDPI};
    const SmartRenderer renderer{window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC};
    renderer.setDrawBlendMode(SDL_BLENDMODE_BLEND);

    TTF_Font* font = mysdl::CheckPointer(TTF_OpenFont("assets/font/Pixeltype.ttf", 50));
    const SmartTexture textTexture{renderer,
                                   SmartSurface{TTF_RenderText_Blended(font, "My game", SDL_Color{0, 255, 0, 255})}};
    const SmartTexture skyTexture{renderer, SmartSurface{IMG_Load("assets/graphics/Sky.png")}};
    const SmartTexture groundTexture{renderer, SmartSurface{IMG_Load("assets/graphics/ground.png")}};

    bool run = true;
    while (run)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0)
        {
            switch (event.type)
            {
            case SDL_QUIT:
                run = false;
                break;
            default:
                break;
            }
        }

        renderer.setDrawColor(SDL_Color{0, 0, 0, 255});
        renderer.clear();

        SDL_Rect skyDst = {0, 0, skyTexture.width(), skyTexture.height()};
        renderer.copy(skyTexture, nullptr, &skyDst);
        SDL_Rect groundDst = {0, 300, groundTexture.width(), groundTexture.height()};
        renderer.copy(groundTexture, nullptr, &groundDst);
        SDL_Rect textDst = {300, 50, textTexture.width(), textTexture.height()};
        renderer.copy(textTexture, nullptr, &textDst);

        renderer.present();
    }

    TTF_CloseFont(font);
    return 0;
}
