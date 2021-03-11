#include "screen.h"

namespace myscreen
{

Screen::Screen(): m_window(NULL),
                  m_renderer(NULL),
                  m_texture(NULL),
                  m_buffer(NULL)
{

}


bool Screen::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }

    m_window = SDL_CreateWindow("Fire explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(m_window == NULL) {
        SDL_Quit();
        return false;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
                                           SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);


    if (m_renderer == NULL) {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    if (m_texture == NULL) {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }

    m_buffer = new Uint32[SCREEN_HEIGHT*SCREEN_WIDTH];
    memset(m_buffer, 0, SCREEN_HEIGHT*SCREEN_WIDTH*sizeof(Uint32));

    for(int i=0; i<SCREEN_HEIGHT*SCREEN_HEIGHT; i++) {
        m_buffer[i] = 0x0000FFFF;
    }

    return true;

};
bool Screen::processEvent()
{
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
        return false;
        }
    }
    return true;
};
void Screen::close()
{
    delete [] m_buffer;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
};

void Screen::update()
{
    SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_HEIGHT*sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
}

void Screen::setPixels(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
    if (x < 0 || x >= SCREEN_WIDTH || y<0 || y>= SCREEN_HEIGHT) {
        return;
    }

    Uint32 color;

    color += red;
    color <<= 8;
    color += green;
    color <<= 8;
    color += blue;
    color <<= 8;
    color += 0x00;
    m_buffer[(SCREEN_WIDTH*y) + x] = color;


}

void Screen::clear(){
    memset(m_buffer, 0, SCREEN_HEIGHT*SCREEN_WIDTH*sizeof(Uint32));

}

Screen::~Screen()
{
    //dtor
}
}
