#ifndef SCREEN_H
#define SCREEN_H
#include <SDL.h>
#include <stdio.h>
#include <string.h>
namespace myscreen{
class Screen
{
    public:
        const static int SCREEN_WIDTH = 800;
        const static int SCREEN_HEIGHT = 600;

    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_buffer;

    public:
        Screen();
        virtual ~Screen();
        bool init();
        bool processEvent();
        void close();
        void update();
        void setPixels(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
};
}
#endif // SCREEN_H
