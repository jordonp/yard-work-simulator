#ifndef RENDERER_H
#define RENDERER_H

#include "level.h"
#include <GL/glew.h>
#include <SDL.h>
#include <string>

class renderer
{
	level* current_level;
	SDL_Window *mainwindow;
	SDL_GLContext maincontext;
	

public:
	GLuint program;
	renderer();
	~renderer();
	void set_level(level& level);
	void render();
};
#endif