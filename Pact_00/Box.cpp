#include "Box.h"

Box::Box(float topLeft[2], float bottomRight[2])
	: topLeft {topLeft[0], topLeft[1]},
	  bottomRight {bottomRight[0], bottomRight[1]}
{
	// Initialize vertices
	updateVertices();
	vertices[2] = 0.0f;
	vertices[5] = 0.0f;
	vertices[8] = 0.0f;
	vertices[11] = 0.0f;

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

void Box::draw()
{
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Box::updateVertices()
{
	// Top right
	vertices[0] = bottomRight[0];
	vertices[1] = topLeft[1];
	// Bottom right
	vertices[3] = bottomRight[0];
	vertices[4] = bottomRight[1];
	// Bottom left
	vertices[6] = topLeft[0];
	vertices[7] = bottomRight[1];
	// Top left
	vertices[9] = topLeft[0];
	vertices[10] = topLeft[1];
}

