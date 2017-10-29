/************************************************
Materia: Graficas Computacionales
Fecha: 29 de Octubre del 2017
Autor: A01166322 Francisco Villafranca
************************************************/

#include <iostream>
#include <memory>
#include <GL/glew.h>
#include <iomanip>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include "InputFile.h"
#include <vector>
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Shader.h"
#include "Transform.h"


Transform rotation;
Transform translation;
Transform scale;
Transform combined;



void PrintTransform(Transform& t) 
{
	glm::mat4 _modelMatrix = t.GetModelMatrix();
	for (size_t i = 0; i < _modelMatrix.length(); i++) 
	{
		for (size_t j = 0; j < _modelMatrix.length(); j++) 
		{
			std::cout << std::setw(10) << std::left << _modelMatrix[j][i] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


void initialize() 
{
	rotation.SetRotation(45, 90, 30);
	PrintTransform(rotation);

	translation.SetPosition(3, 5, -7);
	PrintTransform(translation);

	scale.SetScale(2, 3, 4);
	PrintTransform(scale);

	combined.SetRotation(45, 90, 30);
	combined.SetPosition(3, 5, -7);
	combined.SetScale(2, 3, 4);

	PrintTransform(combined);

}

int main() {
	
	return 0;
}
