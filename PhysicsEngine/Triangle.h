#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <glad/glad.h>

#include "Shader.h"

class Triangle
{
    unsigned int VAO;
    //verticies
    float vertices[9] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

public:
    Triangle();
    ~Triangle() {};

    void InitDrawingData();
    void Draw(Shader* shader);
};

#endif
