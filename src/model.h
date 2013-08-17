#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <glm/glm.hpp>
#include <GL/glew.h>

class renderer;

struct triangle_group
{
	std::vector<int> triangles;
	glm::vec3 colour;
};

class model
{
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<triangle_group> triangle_groups;

	//opengl stuff
	GLuint a_vertices, a_normals, a_triangles;

	void delete_model();
public:
	model();
	~model();

	void upload(renderer& r);
	void render();
};
#endif