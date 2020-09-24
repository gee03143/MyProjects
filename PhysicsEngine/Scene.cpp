#include "Scene.h"

Scene::Scene(float width, float height)
{
    shader = new Shader("Shaders/vertex.txt", "Shaders/fragment.txt");
    camera = new Camera(glm::vec3(400.0, 300.0, 1000.0), width, height, *shader);

    shapes.insert(std::pair<std::string, Shape*>("triangle", new Triangle(
        glm::vec2(400.0, 300.0), glm::vec2(150.0, 150.0), glm::vec3(1.0, 0.5, 0.5)
    )
        ));

    shapes.insert(std::pair<std::string, Shape*>("triangle2", new Triangle(
        glm::vec2(150.0, 450.0), glm::vec2(150.0, 150.0), glm::vec3(1.0, 1.0, 1.0)
    )
        ));

    shapes.insert(std::pair<std::string, Shape*>("aabb", new Aabb(
        glm::vec2(700.0, 100.0), glm::vec2(750.0, 500.0), glm::vec2(1.0, 1.0), glm::vec3(0.5, 0.5, 1.0)
    )
        ));

    shapes.insert(std::pair<std::string, Shape*>("circle", new Circle(
        glm::vec2(600.0, 400.0), glm::vec2(1.0, 1.0), glm::vec3(0.5, 0.5, 1.0), 32.0f
    )
        ));
}

Scene::~Scene()
{
}

void Scene::Draw()
{
    for (auto iter = shapes.begin(); iter != shapes.end(); iter++) {
        iter->second->Draw(shader);
    }

}

void Scene::Update(float dt)
{
    for (auto iter = shapes.begin(); iter != shapes.end(); iter++) {
        iter->second->Position.y -= 0.01f * dt;
    }
}