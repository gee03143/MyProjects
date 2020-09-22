#include "Triangle.h"

Triangle::Triangle(glm::vec2 position, glm::vec2 scale, glm::vec3 color)
    :Shape(position,scale,color)
{
    InitDrawingData();
}

void Triangle::InitDrawingData()
{
    //verticies
    float vertices[9] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.36f, 0.0f 
    };

	unsigned int VBO;
    glGenBuffers(1, &VBO);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void Triangle::Draw(Shader* shader)
{
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(Position, 0.0f));
    model = glm::scale(model, glm::vec3(Scale, 0.0f));
    shader->SetMat4("model", model);

    shader->SetVec4("inputColor", glm::vec4(Color,0.0f));
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}
