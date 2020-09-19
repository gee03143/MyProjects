#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.h"

class Triangle
{
    glm::vec2 Position;
    glm::vec2 Scale;


    unsigned int VAO;
    //verticies
    float vertices[9] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

public:
    Triangle(glm::vec2 position, glm::vec2 scale);
    ~Triangle() {};

    void InitDrawingData();
    void Draw(Shader* shader);
};

#endif
