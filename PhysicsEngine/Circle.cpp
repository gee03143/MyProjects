#include <vector>

#include "Circle.h"

Circle::Circle(glm::vec2 position, glm::vec2 scale, glm::vec3 color, float radius)
	:Shape(position, scale, color), Radius(radius)
{
    InitDrawingData();
}

void Circle::InitDrawingData()
{
    std::vector<float> vertices;

    float theta = 0.0f;
    float dtheta = 360.0f / TRIANGLE_NUM;
    for (int i = 0; i < TRIANGLE_NUM; i++) {
        vertices.push_back(glm::cos(glm::radians(theta)) * Radius);
        vertices.push_back(glm::sin(glm::radians(theta)) * Radius);
        theta += dtheta;
    }

    unsigned int VBO;
    glGenBuffers(1, &VBO);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices.front(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void Circle::Draw(Shader* shader)
{
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(Position, 0.0f));
    trans = glm::scale(trans, glm::vec3(Scale, 0.0f));
    shader->SetMat4f("transform", trans);

    shader->SetFloat4("inputColor", glm::vec4(Color, 0.0f));

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLE_FAN, 0, TRIANGLE_NUM);
    glBindVertexArray(0);
}
