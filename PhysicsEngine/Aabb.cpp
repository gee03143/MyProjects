#include "Aabb.h"

Aabb::Aabb(glm::vec2 min, glm::vec2 max, glm::vec2 scale, glm::vec3 color)
    :Minpoint(min), Maxpoint(max)
{
    this->Position = glm::vec2((max.x - min.x) / 2, (max.y - min.y) / 2);
    this->Scale = scale;
    this->Color = color;

    InitDrawingData();
}

void Aabb::InitDrawingData()
{
    //verticies
    float vertices[12] = {
        Minpoint.x, Maxpoint.y, 0.0f, //vertex 0 : Top-left 
        Maxpoint.x, Maxpoint.y, 0.0f,  //vertex 1 : Top-right   
        Maxpoint.x, Minpoint.y, 0.0f, //vertex 2 : Bottom-right
        Minpoint.x, Minpoint.y, 0.0f,  //vertex 3 : Bottom-left  
    };

    //indices
    unsigned int indices[6] = {
        0,1,3,
        1,2,3
    };

    unsigned int VBO;
    glGenBuffers(1, &VBO);

    unsigned int EBO;
    glGenBuffers(1, &EBO);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void Aabb::Draw(Shader* shader)
{
    glm::mat4 model = glm::mat4(1.0f);
    //model = glm::translate(model, glm::vec3(Position, 0.0f));
    model = glm::scale(model, glm::vec3(Scale, 0.0f));
    shader->SetMat4("model", model);

    shader->SetVec4("inputColor", glm::vec4(Color, 0.0f));
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}