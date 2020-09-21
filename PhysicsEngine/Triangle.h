#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
    unsigned int VAO;

public:
    Triangle(glm::vec2 position, glm::vec2 scale, glm::vec3 color);
    ~Triangle() {};

    void InitDrawingData();
    void Draw(Shader* shader);
};

#endif
