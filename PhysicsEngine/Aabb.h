#ifndef AABB_H
#define AABB_H

#include "Shape.h"

class Aabb : public Shape
{
    unsigned int VAO;

    float Width;
    float Height;
public:
    //TODO 두 점으로 생성하는 생성자 만들것
    Aabb(glm::vec2 min, glm::vec2 max, glm::vec2 scale, glm::vec3 color);
    ~Aabb() {};

    void InitDrawingData();
    void Draw(Shader* shader);

};

#endif

