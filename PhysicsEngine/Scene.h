#ifndef SCNEN_H
#define SCENE_H

#include "ShapeHeaders.h"
#include "Camera.h"
#include "Shader.h"
#include "CollisionDetector.h"

#include <map>
#include <string>
#include <iostream>

class Scene
{
	Shader * shader;
	Camera * camera;
	std::map<std::string, Shape*> shapes;


public:
	Scene(float width, float height);
	~Scene();

	void Draw();
	void Update(float dt);
	void CollisionCheck();
};

#endif

