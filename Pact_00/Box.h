#pragma once

#include <GLM\glm.hpp>
#include <iostream>
#include <glad\glad.h>

class Box
{
public:
	// Constructors.
	Box(float topLeft[2], float bottomRight[2]);

	// Functions.
	void draw();

private:
	// Fields.
	GLfloat topLeft[2];
	GLfloat bottomRight[2];
	GLfloat vertices[12];
	const GLfloat indices[6] = { 0, 1, 3, 1, 2, 3 };

	GLuint VAO;
	GLuint VBO;
	GLuint EBO;

	// Functions.
	void updateVertices();
};