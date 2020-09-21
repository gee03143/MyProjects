#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>
#include <string>

class Shader
{
	Shader();	//private 생성자 -> shader 생성 시 반드시 쉐이더 코드 경로가 주어져야 함
	unsigned int ID;

public:
	Shader(std::string vertexPath, std::string fragmentPath);
	~Shader() {}

	void Use();

	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;

	void SetFloat4(const std::string& name, float x, float y, float z, float w) const;

	void SetFloat4(const std::string& name, glm::vec4 value) const;

	void SetMat4f(const std::string& name, glm::mat4 value) const;


};

#endif
