#include <iostream>
#include <vector>
#include "Reader.h"
#include "Screen.h"
#include

using namespace std ;

int main() {


//    Reader r1 ;
//
//    string result = r1.read_line() ;

    Screen screen ;
    screen.init() ;


    bool quit = false ;
    SDL_Event sdl_event ;

    while (!quit) {
        // Update Particles
        // Draw Particles
        // Check for messages/events

        while (SDL_PollEvent(&sdl_event)) {
            if(sdl_event.type == SDL_QUIT) {
                quit = true ;
            }
        }
    }


    return 0;
}