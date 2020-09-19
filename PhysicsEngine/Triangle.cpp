#include "Triangle.h"

Triangle::Triangle(glm::vec2 position, glm::vec2 scale)
    :Position(position), Scale(scale)
{
}

void Triangle::InitDrawingData()
{
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
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(Position, 0.0f));
    trans = glm::scale(trans, glm::vec3(Scale, 0.0f));
    shader->SetMat4f("transform", trans);


    shader->SetFloat4("inputColor", 0.7f, 0.5f, 0.5f, 0.0f);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
