#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "model.h"
#include "glm/glm.hpp"
#include "glm/gtx/quaternion.hpp"

struct bounding_box
{
	glm::vec3 max;
	glm::vec3 min;
};

class game_object
{
	model geometry;
	float x;
	float y;
	float z;
	float scale_x;
	float scale_y;
	float scale_z;
	glm::quat roation;
	bounding_box bounds;

public:
	game_object();
	~game_object();
};
#endif