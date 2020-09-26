#ifndef SHAPE_H
#define SHAPE_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.h"

enum ShapeObject_t {
    AABB = 0,
    CIRCLE,
    TRIANGLE,

    SHAPE_OBJECT_COUNT,
};

class Shape
{
    ShapeObject_t type;
protected:
	glm::vec2 Scale;
    glm::vec3 Color;

public:
    glm::vec2 Position;
    Shape();
    Shape(glm::vec2 position, glm::vec2 scale, glm::vec3 color, ShapeObject_t t);
    virtual ~Shape() {};

    virtual void InitDrawingData() = 0;
    virtual void Draw(Shader* shader) = 0;

    ShapeObject_t GetType() { return type; }
};

#endif
