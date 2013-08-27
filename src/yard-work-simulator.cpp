#include <SDL.h>
#include "renderer.h"
#include "level.h"
#include "game_object.h"
#include "camera.h"

game_object* player;

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
                if(player) {
                    if ( event.key.keysym.sym == SDLK_w && player )
                        player->move_forward(0.2f);
                    if ( event.key.keysym.sym == SDLK_a )
                        player->move_left(0.2f);
                    if ( event.key.keysym.sym == SDLK_s )
                        player->move_backward(0.2f);
                    if ( event.key.keysym.sym == SDLK_d )
                        player->move_right(0.2f);
                }
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
    player = &l.view;
    l.view.set_position(-5.0f, 0.0f, 10.0f);
    l.view.set_orientation(-40.0f, 0.0f, 1.0f, 0.0f);

    game_object& cube = l.new_game_object();
    cube.set_colour(1.0f, 0.0f, 0.0f);
    //player = &cube;


    {
        game_object& ground = l.new_game_object();
        ground.set_position(0, -0.5, 0);
        ground.set_scale(100, 1, 100);
        ground.set_colour(0, 0.6, 0);

        for (int i = 0; i < 5; ++i)
        {
            game_object& stump = l.new_game_object();
            stump.set_position(5, 0.0, -5 + i * 3);
            stump.set_colour(0.2, 0.1, 0);

            game_object& bush = l.new_game_object();
            bush.set_scale(2, 3, 2);
            bush.set_position(5, 2, -5 + i * 3);
            bush.set_colour(0.0, 0.4, 0);
        }
    }

    r.set_level(l);

    mainLoop(r);

    return 0;
}