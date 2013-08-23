#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <GL/glew.h>
#include "game_object.h"
#include "camera.h"

class renderer;

class level
{
	std::vector<game_object> objects;

	//openGL stuff
	GLuint u_m, u_minv, u_mvp;
public:
	camera view;
	level();
	~level();
	

	void upload(renderer& r);
	void render();
	void add_object(game_object& object);
};
#endif