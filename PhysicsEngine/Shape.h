#ifndef SHAPE_H
#define SHAPE_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.h"

class Shape
{
protected:

	glm::vec2 Scale;
    glm::vec3 Color;

public:
    glm::vec2 Position;
    Shape();
    Shape(glm::vec2 position, glm::vec2 scale, glm::vec3 color);
    virtual ~Shape() {};

    virtual void InitDrawingData() = 0;
    virtual void Draw(Shader* shader) = 0;


};

#endif
