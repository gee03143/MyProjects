#include "Scene.h"

typedef bool (*CollisionFunction)(Shape* lhs, Shape* rhs);

CollisionFunction collisionCallbackArray[SHAPE_OBJECT_COUNT][SHAPE_OBJECT_COUNT] = {
    {AabbvsAabb, AabbvsCircle, TrianglevsTriangle},
    {CirclevsAabb, CirclevsCircle, TrianglevsTriangle},
    {TrianglevsTriangle,TrianglevsTriangle,TrianglevsTriangle}
};  //  triangle 아직 안만듬, triangle이 polygon으로 바뀔수도 있음

Scene::Scene(float width, float height)
{
    shader = new Shader("Shaders/vertex.txt", "Shaders/fragment.txt");
    camera = new Camera(glm::vec3(400.0, 300.0, 1000.0), width, height, *shader);

    /*
    shapes.insert(std::pair<std::string, Shape*>("triangle", new Triangle(
        glm::vec2(400.0, 300.0), glm::vec2(150.0, 150.0), glm::vec3(1.0, 0.5, 0.5)
    )
        ));

    shapes.insert(std::pair<std::string, Shape*>("triangle2", new Triangle(
        glm::vec2(150.0, 450.0), glm::vec2(150.0, 150.0), glm::vec3(1.0, 1.0, 1.0)
    )
        ));
        */

    shapes.insert(std::pair<std::string, Shape*>("aabb", new Aabb(
        glm::vec2(700.0, 100.0), glm::vec2(800.0, 200.0), glm::vec2(1.0, 1.0), glm::vec3(0.5, 0.5, 1.0)
    )
        ));

    shapes.insert(std::pair<std::string, Shape*>("circle", new Circle(
        glm::vec2(600.0, 300.0), glm::vec2(1.0, 1.0), glm::vec3(0.5, 0.5, 1.0), 141.0f
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
    CollisionCheck();
    for (auto iter = shapes.begin(); iter != shapes.end(); iter++) {
        //iter->second->Position.y -= 0.01f * dt;
    }
    shapes["circle"]->Position.y -= 0.01f * dt;
}

void Scene::CollisionCheck()
{
    for (auto i = shapes.begin(); i != shapes.end(); i++) {
        auto temp = i;
        for (auto j = ++temp; j != shapes.end(); j++) {
            if (collisionCallbackArray[i->second->GetType()][j->second->GetType()](i->second, j->second)) {
                //collision detected do something
                std::cout << "collision between " << i->first << " and " << j->first<<"\n";
            }
        }
    }
}
