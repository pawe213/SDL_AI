#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <string.h>

using namespace std;

//int SDL_main(int, char **);

int main(int argc, char **argv)
{
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    cout << "Hello world!" << endl;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL is working" << endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Fire explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(window == NULL) {
        cout << "Window was NULL" << endl;
        SDL_Quit();
        return 2;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                                           SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);


    if (renderer == NULL) {
        cout << "Could not create renderer" << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 3;
    }
    if (texture == NULL) {
        cout << "Could not create texture" << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 4;
    }

    Uint32 *buffer = new Uint32[SCREEN_HEIGHT*SCREEN_WIDTH];
    memset(buffer, 0xFF, SCREEN_HEIGHT*SCREEN_WIDTH*sizeof(Uint32));

    SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    bool quit = false;
    SDL_Event event;

    while(!quit) {
        // Update particles
        // Draw particles
        // Check for messages/events

        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                quit = true;
            }

        }
    }

    delete [] buffer;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
