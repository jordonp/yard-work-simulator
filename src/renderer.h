#ifndef RENDERER_H
#define RENDERER_H

#include "level.h"
#include <GL/glew.h>
#include <SDL.h>

class renderer
{
	level* current_level;
	SDL_Window *mainwindow;
	SDL_GLContext maincontext;
	GLint attribute_coord2d, uniform_colour;
	GLuint program;

public:
	renderer();
	~renderer();
	void render();
};
#endif