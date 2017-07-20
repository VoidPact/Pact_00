#include "render.h"

void initRenderData()
{
	// Inspired from OpenGL tutorial.
	//Configure VAO/VBO
	GLfloat vertices[] =
	{
		0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f
	};
	unsigned int indices[] =
	{
		0, 1, 3, // first triangle.
		1, 2, 3 // second triangle.
	};

	unsigned int VBO, VAO, EBO;
	// Generate vertex array.
	glGenVertexArrays(1, &VAO);
	
	// Generate buffers
	glGenBuffers(1, &VBO); // Holding the coords (vertices).
	glGenBuffers(1, &EBO); // Holding the sequence to draw elements (indices).

	// Remember first to bind the vertex array.
	glBindVertexArray(VAO);

	// Copy verticies and indices into buffers for OpenGL to use.
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	
	// Set and enable the vertex attributes pointers.
	// Dunno really what this is, but it's got something to do with something.
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

}

void square() 
{
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}