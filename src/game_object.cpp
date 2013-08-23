#include "game_object.h"
#include "glm/gtc/matrix_transform.hpp"

game_object::~game_object() {

}

glm::mat4 game_object::get_matrix() {
	return glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z)) * 
		   glm::mat4_cast(rotation) * 
		   glm::scale(glm::mat4(1.0f), glm::vec3(scale_x, scale_y, scale_z)) * glm::mat4(1.0f);
}

void game_object::set_position(float new_x, float new_y, float new_z) {
	x = new_x;
	y = new_y;
	z = new_z;
}

void game_object::set_scale(float x_scale, float y_scale, float z_scale) {
	scale_x = x_scale;
	scale_y = y_scale;
	scale_z = z_scale;
}

void game_object::set_orientation(float angle, float axis_x, float axis_y, float axis_z) {
	rotation = glm::quat_cast(glm::rotate(glm::mat4(1.0f), angle, glm::vec3(axis_x, axis_y, axis_z)));
}

glm::vec3 game_object::move(float x_amount, float y_amount, float z_amount) {
	x += x_amount;
	y += y_amount;
	z += z_amount;
}

glm::quat game_object::rotate(float angle, float axis_x, float axis_y, float axis_z) {
	rotation = glm::quat_cast(glm::rotate(glm::mat4(1.0f), angle, glm::vec3(axis_x, axis_y, axis_z)) * glm::mat4_cast(rotation));
}

bool game_object::collide(float point_x, float point_y, float point_z) {

}

bool game_object::collide(game_object object) {

}

void game_object::set_colour(float r, float g, float b) {
	geometry.set_colour(-1, glm::vec3(r, g, b));
}
