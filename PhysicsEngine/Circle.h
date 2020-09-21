#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
    unsigned int VAO;

    const int TRIANGLE_NUM = 32;   
    float Radius;

public:
    Circle(glm::vec2 position, glm::vec2 scale, glm::vec3 color, float radius);
    ~Circle() {};

    void InitDrawingData();
    void Draw(Shader* shader);
};

#endif

