#include "level.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "renderer.h"

level::level() {

}

level::~level() {

}

void level::upload(renderer& r) {
	u_m = glGetUniformLocation(r.program, "m");
    u_mvp = glGetUniformLocation(r.program, "mvp");
    u_minv = glGetUniformLocation(r.program, "minv");
    for (int i = 0; i < objects.size(); ++i)
    {
    	objects[i].geometry.upload(r);
    }
}

void level::render() {
	glm::mat4 camera_matrix = view.get_view();
	for (int i = 0; i < objects.size(); ++i)
	{
		glm::mat4 m = objects[i].get_matrix();

		glm::mat3 m_inv = glm::mat3(glm::inverse(m));

		glm::mat4 mvp = camera_matrix * m;

		glUniformMatrix4fv(u_m, 1, GL_FALSE, glm::value_ptr(m));
        glUniformMatrix3fv(u_minv, 1, GL_FALSE, glm::value_ptr(m_inv));
        glUniformMatrix4fv(u_mvp, 1, GL_FALSE, glm::value_ptr(mvp));
        
        objects[i].geometry.render();
	}
}

void level::add_object(game_object& object) {
	objects.push_back(object);
}