#include <SDL.h>
#include "renderer.h"

void mainLoop(renderer& r) {
    SDL_Event event;
    int status;
    bool quit = false;

    while ( !quit ) {             
        while( SDL_PollEvent( &event ) ){
            switch (event.type) {      
              case SDL_KEYDOWN:     
                if ( event.key.keysym.sym == SDLK_ESCAPE )
                    quit = true;
                break;
             case SDL_QUIT:
                quit = true;
                break;
            }
        }
        r.render();
    }
}
 
int main(int argc, char *argv[])
{
    renderer r;

    mainLoop(r);

    return 0;
}