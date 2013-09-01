#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "model.h"
#include "glm/glm.hpp"
#include "glm/gtx/quaternion.hpp"

struct bounding_box
{
	glm::vec3 max;
	glm::vec3 min;
	bounding_box() : max(0.0f, 0.0f, 0.0f), min(0.0f, 0.0f, 0.0f) {}
};

class game_object
{
protected:
	float x;
	float y;
	float z;
	float scale_x;
	float scale_y;
	float scale_z;
	glm::quat rotation;
	bounding_box bounds;
public:
	model geometry;
	game_object() : x(0), y(0), z(0), scale_x(1.0f), scale_y(1.0f), scale_z(1.0f), rotation(1.0f, 0.0f, 0.0f, 0.0f) {}
	virtual ~game_object();
	glm::mat4 get_matrix();
	void set_x(float new_x);
	void set_y(float new_y);
	void set_z(float new_z);
	void set_position(float new_x, float new_y, float new_z);
	void set_scale(float x_scale, float y_scale, float z_scale);
	void set_orientation(float angle, float axis_x, float axis_y, float axis_z);
	glm::vec3 move(float x_amount, float y_amount, float z_amount);
	glm::vec3 move_forward(float amount);
	glm::vec3 move_backward(float amount);
	glm::vec3 move_left(float amount);
	glm::vec3 move_right(float amount);
	glm::quat rotate(float angle, float axis_x, float axis_y, float axis_z);
	glm::quat pitch(float angle);
	glm::quat roll(float angle);
	glm::quat yaw(float angle);
	bool collide(float point_x, float point_y, float point_z);
	bool collide(game_object object);
	void set_colour(float r, float g, float b);
};
#endif