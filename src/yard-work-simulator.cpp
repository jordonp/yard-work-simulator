#include <SDL.h>
#include "renderer.h"
#include "level.h"
#include "game_object.h"

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

    level l;

    l.view.set_position(-5.0f, 1.0f, 5.0f);
    l.view.set_orientation(90.0f, 0.0f, 1.0f, 0.0f);

    {
        game_object ground;
        ground.set_scale(100, 1, 100);
        ground.set_colour(0, 0.6, 0);
        l.add_object(ground);

        for (int i = 0; i < 5; ++i)
        {
            game_object stump;
            stump.set_position(5, 0.5, -5 + i * 3);
            stump.set_colour(0.2, 0.1, 0);
            l.add_object(stump);

            game_object bush;
            bush.set_scale(2, 3, 2);
            bush.set_position(5, 2, -5 + i * 3);
            bush.set_colour(0.0, 0.4, 0);
            l.add_object(bush);
        }
    }

    r.set_level(l);

    mainLoop(r);

    return 0;
}