#include "Shape.h"

Shape::Shape()
	:Position(glm::vec2(0.0f)), Scale(glm::vec2(0.0f)), Color(glm::vec3(0.0f))
{

}

Shape::Shape(glm::vec2 position, glm::vec2 scale, glm::vec3 color, ShapeObject_t t)
	:Position(position), Scale(scale), Color(color), type(t)
{

}