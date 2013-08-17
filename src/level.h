#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "gameobject.h"

class renderer;

class level
{
	std::vector<game_object> objects;
public:
	level();
	~level();

	void upload(renderer& r);
	void render();
};
#endif