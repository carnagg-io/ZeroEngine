#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#undef main

namespace ZEngine
{
    class Renderer
    {
    private:
        // Make own window class?
        SDL_Window* m_Window;
        SDL_Surface* m_Surface;

    protected:
        Renderer();
        ~Renderer();

        static Renderer* m_instance;

    public:
        Renderer(Renderer &ref) = delete;
        void operator = (const Renderer&) = delete;

        static Renderer* instance();

        bool initialize();
        bool loop();
        bool terminate();
    };
}

#endif // RENDERER_H