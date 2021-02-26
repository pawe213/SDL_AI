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



    bool quit = false;


    while(true) {
        // Update particles
        // Draw particles
        // Check for messages/events

        if(screen.processEvent() == false){
            break;
        }


    }


    return 0;
}
