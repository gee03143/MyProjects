#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(glm::vec3 position, float width, float height, Shader& shader)
	:cameraPos(position), cameraTarget(glm::vec3(0.0f)), screenWidth(width), screenHeight(height)
{
	shaderRef = &shader;

	lookAtMatrix = glm::mat4(1.0f);
	SetOrthographic(-0.1f, 100.0f);
}

Camera::~Camera() {

}

void Camera::LookAt(glm::vec3 target)
{
	cameraTarget = target;
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

	glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);

	glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));

	glm::vec3 cameraUp = glm::normalize(glm::cross(cameraDirection, cameraRight));

	glm::mat4 rotate = glm::mat4(1.0f);
	rotate[0][0] = cameraRight.x;
	rotate[0][1] = cameraRight.y;
	rotate[0][2] = cameraRight.z;
	rotate[1][0] = cameraUp.x;
	rotate[1][1] = cameraUp.y;
	rotate[1][2] = cameraUp.z;
	rotate[2][0] = cameraDirection.x;
	rotate[2][1] = cameraDirection.y;
	rotate[2][2] = cameraDirection.z;

	glm::mat4 translate = glm::mat4(1.0f);
	translate[3][0] = -cameraPos.x;
	translate[3][1] = -cameraPos.y;
	translate[3][2] = -cameraPos.z;

	/* lookAtMatrix = 
	* [R.x R.y R.z 0.0]		[1.0 0.0 0.0 -P.x]
	* [U.x U.y U.z 0.0]		[0.0 1.0 0.0 -P.y]
	* [D.x D.y D.z 0.0]  *  [0.0 0.0 1.0 -P.z]
	* [0.0 0.0 0.0 1.0]		[0.0 0.0 0.0  1.0]
	*/

	lookAtMatrix = rotate * translate;
}

void Camera::SetOrthographic(float near, float far)
{
	isPerspective = false;
	//ortho
	glm::mat4 view = glm::mat4(1.0f);
	shaderRef->SetMat4("view", view);

	glm::mat4 projection = glm::ortho(0.0f, screenWidth, 0.0f, screenHeight, -0.1f, 100.0f);
	shaderRef->SetMat4("projection", projection);
}

void Camera::SetPerspective(float fov, float near, float far)
{
	isPerspective = true;
	//perspective
	LookAt(glm::vec3(400.0, 300.0, 0.0));
	glm::mat4 view = lookAtMatrix;
	shaderRef->SetMat4("view", view);

	glm::mat4 projection = glm::perspective(glm::radians(45.0f), screenWidth / screenHeight, -10.0f, 100.0f);
	shaderRef->SetMat4("projection", projection);
}
