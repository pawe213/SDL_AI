#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <string.h>
#include "screen.h"

using namespace std;
using namespace myscreen;

//int SDL_main(int, char **);

int main(int argc, char **argv)
{

    cout << "Hello world!" << endl;
    Screen screen;
    if (screen.init()== false){
        cout << "Error initialising SDL" << endl;
    }


    for (int y = 0; y < screen.SCREEN_HEIGHT; y++){
        for(int x = 0; x < screen.SCREEN_WIDTH; x++){
            screen.setPixels(x, y, 0x10, 0x10, 0x10);
        }
    }



    bool quit = false;
    while(true) {
        // Update particles
        // Draw particles
        // Check for messages/events

        screen.update();

        if(screen.processEvent() == false){
            break;
        }


    }


    return 0;
}
