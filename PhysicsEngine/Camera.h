#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

#include "Shader.h"

class Camera
{
	Shader * shaderRef;

	bool isPerspective = false;

	float screenWidth;
	float screenHeight;

	glm::vec3 cameraPos;
	glm::vec3 cameraTarget;

	glm::mat4 lookAtMatrix;
	
public:
	Camera(glm::vec3 position, float width, float height, Shader& shader);
	~Camera();

	void LookAt(glm::vec3 target);
	void SetOrthographic(float near, float far);
	void SetPerspective(float fov, float near, float far);
};

#endif

