#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <string.h>
#include "screen.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <swarm.h>

using namespace std;
using namespace myscreen;

//int SDL_main(int, char **);

int main(int argc, char **argv)
{
    srand(time(NULL));
    Screen screen;
    if (screen.init()== false){
        cout << "Error initialising SDL" << endl;
    }

//
//    for (int y = 0; y < screen.SCREEN_HEIGHT; y++){
//        for(int x = 0; x < screen.SCREEN_WIDTH; x++){
//            screen.setPixels(x, y, 0, 0, - 255);
//        }
//    }

    Swarm swarm;

    bool quit = false;
    while(true) {
        int elapsed = SDL_GetTicks();
        // Update particles
        screen.clear();
        swarm.update();
        // Draw particles

        unsigned char green = (1 + sin(elapsed*0.0001)) * 128;
        unsigned char red = (1 + sin(elapsed*0.0002)) * 128;
        unsigned char blue = (1 + sin(elapsed*0.0003)) * 128;

        const Particle * const pParticles = swarm.getParticles();
        for (int i=0; i<Swarm::NPARTICLES; i++) {
            Particle particle = pParticles[i];
            int x = (particle.m_x + 1) *(Screen::SCREEN_WIDTH/2);
//            int y = (particle.m_y + 1) *(Screen::SCREEN_HEIGHT/2);
            int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT/2;
            screen.setPixel(x, y, red, green, blue);

        }

        /*


        for (int y = 0; y < screen.SCREEN_HEIGHT; y++){
            for(int x = 0; x < screen.SCREEN_WIDTH; x++){
                screen.setPixels(x, y, red, green, blue);
            }
        }

        */
        // Check for messages/events

        screen.update();

        if(screen.processEvents() == false){
            break;
        }


    }

    screen.close();
    return 0;
}
