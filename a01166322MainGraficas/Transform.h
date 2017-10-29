#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <vector>
#include <memory>


class Transform
{

public:
	Transform();
	glm::mat4 GetModelMatrix();
	glm::vec3 GetPosition();
	glm::quat GetRotation();
	glm::vec3 GetScale();

	void SetPosition(float x, float y, float z);
	void SetRotation(float x, float y, float z);
	void SetScale(float x, float y, float z);

private:
	void UpdateModelMatrix();
	glm::mat4 _modelMatrix;
	glm::vec3 _position;
	glm::quat _rotation;
	glm::vec3 _scale;
};