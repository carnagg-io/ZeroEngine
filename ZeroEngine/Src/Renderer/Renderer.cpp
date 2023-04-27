#include "Renderer\Renderer.h"
#include "Common.h"

namespace ZEngine
{
    Renderer* Renderer::m_instance = nullptr;

    Renderer::Renderer()
    {
        m_Window = NULL;
        m_Surface = NULL;
    }

    Renderer::~Renderer()
    {
    }

    Renderer* Renderer::instance()
    {
        if (m_instance == nullptr)
        {
            m_instance = new Renderer();
        }
        return m_instance;
    }

    bool Renderer::initialize()
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            LOGF_CRIT("[[[VIDEO INIT FAILED]]] Error: %s\n", SDL_GetError());
            return false;
        }
        else
        {
            int resX = 1920;
            int resY = 1080;

            if (Settings* settings = Settings::instance())
            {
                resX = settings->resX();
                resY = settings->resY();
            }
            
            // All of these values should come from settings.
            if (m_Window = SDL_CreateWindow("Tempyo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, resX, resY, SDL_WINDOW_SHOWN))
            {
                if (m_Surface = SDL_GetWindowSurface(m_Window))
                {
                    SDL_FillRect(m_Surface, NULL, SDL_MapRGB(m_Surface->format, 0xFF, 0xFF, 0xFF));
                    SDL_UpdateWindowSurface(m_Window);
                    SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
                    return true;
                }
                else
                {
                    LOGF_CRIT("[[[SURFACE INIT FAILED]]] Error: %s\n", SDL_GetError());
                    return false;
                }
            }
            else
            {
                LOGF_CRIT("[[[WINDOW INIT FAILED]]] Error: %s\n", SDL_GetError());
                return false;
            }
        }

        return false;
    }

    bool Renderer::loop()
    {
        SDL_Event e;
        bool quit = false;
        while (quit == false)
        {
            while (SDL_PollEvent(&e))
            {
                if (e.type == SDL_QUIT)
                    quit = true;
            }
        }
        return true;
    }

    bool Renderer::terminate()
    {
        SDL_DestroyWindow(m_Window);
        SDL_Quit();
        return true;
    }
}