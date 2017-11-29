/************************************************
Materia: Graficas Computacionales
Fecha: 28 de Noviembre del 2017
Autor: A01166322 Francisco Villafranca  :)
A01374365 Edgar Saul Ortiz Borja :)
************************************************/

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include <IL/il.h>
#include "Camera.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Transform.h"
#include "Texture2D.h"

Camera _camera;
Mesh _mesh;
Transform _transform; //padre
Transform _transform2; //piso
Transform _c1;
Transform _c2;
Transform _c3;
Transform _c4;
Transform _c5;
Transform _jc1;
Transform _jc2;
Transform _jc3;
Transform _jc4;
Transform _jc5;

ShaderProgram _shaderProgram;
Texture2D _cubeBaseTexture;
Texture2D _cubeDetailTexture;
float rotacion = 0.0f;
float delta = 0.0f;

// Función que va a inicializar toda la memoria del programa.
void Initialize()
{

	_cubeBaseTexture.LoadTexture("piso.jpg");
	_cubeDetailTexture.LoadTexture("yomama.jpg");
	// Vamos a crear una lista que va a almacenar las posiciones
	// en 2 dimensiones de un triángulo.
	// Esto es en CPU y RAM.
	std::vector<glm::vec3> positions;
	// Cara frontal
	positions.push_back(glm::vec3(-3.0f, -0.2f, 3.0f));
	positions.push_back(glm::vec3(3.0f, -0.2f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 0.2f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, 0.2f, 3.0f));
	// Cara lateral derecha
	positions.push_back(glm::vec3(3.0f, -0.2f, 3.0f));
	positions.push_back(glm::vec3(3.0f, -0.2f, -3.0f));
	positions.push_back(glm::vec3(3.0f, 0.2f, -3.0f));
	positions.push_back(glm::vec3(3.0f, 0.2f, 3.0f));
	//Cara Trasera
	positions.push_back(glm::vec3(3.0f, -0.2f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, -0.2f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, 0.2f, -3.0f));
	positions.push_back(glm::vec3(3.0f, 0.2f, -3.0f));
	//Cara lateral izquierda
	positions.push_back(glm::vec3(-3.0f, -0.2f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, -0.2f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, 0.2f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, 0.2f, -3.0f));
	//Cara Superior
	positions.push_back(glm::vec3(-3.0f, 0.2f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 0.2f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 0.2f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, 0.2f, -3.0f));

	//Cara Inferior 
	positions.push_back(glm::vec3(-3.0f, -0.2f, -3.0f));
	positions.push_back(glm::vec3(3.0f, -0.2f, -3.0f));
	positions.push_back(glm::vec3(3.0f, -0.2f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, -0.2f, 3.0f));


	// Vamos a crear una lista para almacenar colores RGB
	// Esta lista está en CPU y RAM
	std::vector<glm::vec3> colors;
	// Cara frontal
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	// Cara lateral derecha
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	//Cara trasera
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	//Cara lateral izquierda
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	//Cara superior
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	//Cara inferior
	colors.push_back(glm::vec3(0.5f, 0.5f, 1.0f));
	colors.push_back(glm::vec3(0.5f, 0.5f, 1.0f));
	colors.push_back(glm::vec3(0.4f, 0.5f, 1.0f));
	colors.push_back(glm::vec3(0.5f, 0.5f, 1.0f));

	//Lista de normales
	std::vector<glm::vec3> normals;
	// Cara frontal
	normals.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	// Cara lateral derecha
	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	//Cara Trasera
	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	//Cara lateral izquierda
	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	//Cara Superior
	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));

	//Cara Inferior 
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));

	std::vector<glm::vec2> textures;
	// Cara frontal
	textures.push_back(glm::vec2(0.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 1.0f));
	textures.push_back(glm::vec2(0.0f, 1.0f));
	// Cara lateral derecha
	textures.push_back(glm::vec2(0.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 1.0f));
	textures.push_back(glm::vec2(0.0f, 1.0f));
	//Cara Trasera
	textures.push_back(glm::vec2(0.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 1.0f));
	textures.push_back(glm::vec2(0.0f, 1.0f));
	//Cara lateral izquierda
	textures.push_back(glm::vec2(0.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 1.0f));
	textures.push_back(glm::vec2(0.0f, 1.0f));
	//Cara Superior
	textures.push_back(glm::vec2(0.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 1.0f));
	textures.push_back(glm::vec2(0.0f, 1.0f));
	//Cara Inferior 
	textures.push_back(glm::vec2(0.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 1.0f));
	textures.push_back(glm::vec2(0.0f, 1.0f));





	std::vector<unsigned int> indices = { 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7,8,9,10,8,10,11,12,14,15,12,13,14,16,18,19,16,17,18,20,22,23,20,21,22 };

	_mesh.CreateMesh(24);
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	_mesh.SetNormalAttribute(normals, GL_STATIC_DRAW, 2);
	_mesh.SetTexCoordAttribute(textures, GL_STATIC_DRAW, 3);
	_mesh.SetIndices(indices, GL_STATIC_DRAW);


	_shaderProgram.CreateProgram();
	_shaderProgram.AttachShader("Textured.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("Textured.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_shaderProgram.SetAttribute(2, "VertexNormal");
	_shaderProgram.SetAttribute(3, "VertexTexCoord");
	_shaderProgram.LinkProgram();


	_transform.SetPosition(0.0f, -5.0f, -20.0f); //base
	_transform2.SetPosition(0.0f, -6.0f, -20.0f); //piso
	_c1.SetPosition(-3.0f, 0.0f, 0.0f);
	_c2.SetPosition(0.0f, 0.0f, -3.0f);
	_c3.SetPosition(0.0f, 0.0f, 3.0f);
	_c4.SetPosition(3.0f, 0.0f, 0.0f);
	_c5.SetPosition(3.0f, 0.0f, 0.0f);
	_jc1.SetPosition(-3.0f, 0.0f, 0.0f);
	_jc2.SetPosition(0.0f, 0.0f, -3.0f);
	_jc3.SetPosition(0.0f, 0.0f, 3.0f);
	_jc4.SetPosition(3.0f, 0.0f, 0.0f);
	_jc5.SetPosition(3.0f, 0.0f, 0.0f);




}



void MainLoop()
{
	// Animacion //
	delta += 0.002f;

	if (rotacion <= 90.0f) {
		rotacion = rotacion + delta;
	}
	if (rotacion >= 90.0f) {
		delta = delta * -1.0f;
		rotacion = rotacion + delta;
	}
	_transform.Rotate(0.00f, 0.05f, 0.00f, true);



	_jc1.SetRotation(0.0f, 0.0f, -rotacion);
	_jc2.SetRotation(rotacion, 0.0f, 0.0f);
	_jc3.SetRotation(-rotacion, 0.0f, 0.0f);
	_jc4.SetRotation(0.0f, 0.0f, rotacion);
	_jc5.SetRotation(0.0f, 0.0f, rotacion);
	////////////////////////////////////////////////////////////////

	// Borramos el buffer de color y profundidad siempre al inicio de un nuevo frame.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);






	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix());
	_shaderProgram.SetUniformf("LightPosition", glm::vec3(-5.0f, 5.0f, 5.0f));
	_shaderProgram.SetUniformf("LightColor", glm::vec3(1.0f, 1.0f, 1.0f));
	_shaderProgram.SetUniformf("CameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("DiffuseTexture1", 1);
	/////
	glActiveTexture(GL_TEXTURE0);
	_cubeBaseTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_cubeDetailTexture.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE1);
	_cubeDetailTexture.Unbind();
	glActiveTexture(GL_TEXTURE0);
	_cubeBaseTexture.Unbind();

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix() * _jc1.GetModelMatrix() *  _c1.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix() * _jc1.GetModelMatrix() *  _c1.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix() * _jc1.GetModelMatrix() *  _c1.GetModelMatrix());
	_shaderProgram.SetUniformf("LightPosition", glm::vec3(-5.0f, 5.0f, 5.0f));
	_shaderProgram.SetUniformf("LightColor", glm::vec3(1.0f, 1.0f, 1.0f));
	_shaderProgram.SetUniformf("CameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("DiffuseTexture1", 1);
	/////
	glActiveTexture(GL_TEXTURE0);
	_cubeBaseTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_cubeDetailTexture.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE1);
	_cubeDetailTexture.Unbind();
	glActiveTexture(GL_TEXTURE0);
	_cubeBaseTexture.Unbind();

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix() * _jc2.GetModelMatrix() *  _c2.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix() * _jc2.GetModelMatrix() *  _c2.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix() * _jc2.GetModelMatrix() *  _c2.GetModelMatrix());
	_shaderProgram.SetUniformf("LightPosition", glm::vec3(-5.0f, 5.0f, 5.0f));
	_shaderProgram.SetUniformf("LightColor", glm::vec3(1.0f, 1.0f, 1.0f));
	_shaderProgram.SetUniformf("CameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("DiffuseTexture1", 1);
	/////
	glActiveTexture(GL_TEXTURE0);
	_cubeBaseTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_cubeDetailTexture.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE1);
	_cubeDetailTexture.Unbind();
	glActiveTexture(GL_TEXTURE0);
	_cubeBaseTexture.Unbind();

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix() * _jc3.GetModelMatrix() *  _c3.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix() * _jc3.GetModelMatrix() *  _c3.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix() * _jc3.GetModelMatrix() *  _c3.GetModelMatrix());
	_shaderProgram.SetUniformf("LightPosition", glm::vec3(-5.0f, 5.0f, 5.0f));
	_shaderProgram.SetUniformf("LightColor", glm::vec3(1.0f, 1.0f, 1.0f));
	_shaderProgram.SetUniformf("CameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("DiffuseTexture1", 1);
	/////
	glActiveTexture(GL_TEXTURE0);
	_cubeBaseTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_cubeDetailTexture.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE1);
	_cubeDetailTexture.Unbind();
	glActiveTexture(GL_TEXTURE0);
	_cubeBaseTexture.Unbind();

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix() * _jc4.GetModelMatrix() *  _c4.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix() * _jc4.GetModelMatrix() *  _c4.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix() * _jc4.GetModelMatrix() *  _c4.GetModelMatrix());
	_shaderProgram.SetUniformf("LightPosition", glm::vec3(-5.0f, 5.0f, 5.0f));
	_shaderProgram.SetUniformf("LightColor", glm::vec3(1.0f, 1.0f, 1.0f));
	_shaderProgram.SetUniformf("CameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("DiffuseTexture1", 1);
	/////
	glActiveTexture(GL_TEXTURE0);
	_cubeBaseTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_cubeDetailTexture.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE1);
	_cubeDetailTexture.Unbind();
	glActiveTexture(GL_TEXTURE0);
	_cubeBaseTexture.Unbind();

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix() * _jc4.GetModelMatrix() *_c4.GetModelMatrix() * _jc5.GetModelMatrix() *  _c5.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix() * _jc4.GetModelMatrix() *_c4.GetModelMatrix() * _jc5.GetModelMatrix() *  _c5.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix() * _jc4.GetModelMatrix() *_c4.GetModelMatrix() * _jc5.GetModelMatrix() *  _c5.GetModelMatrix());
	_shaderProgram.SetUniformf("LightPosition", glm::vec3(-5.0f, 5.0f, 5.0f));
	_shaderProgram.SetUniformf("LightColor", glm::vec3(1.0f, 1.0f, 1.0f));
	_shaderProgram.SetUniformf("CameraPosition", _camera.GetPosition());
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("DiffuseTexture1", 1);
	/////
	glActiveTexture(GL_TEXTURE0);
	_cubeBaseTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_cubeDetailTexture.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE1);
	_cubeDetailTexture.Unbind();
	glActiveTexture(GL_TEXTURE0);
	_cubeBaseTexture.Unbind();

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




	_transform2.SetScale(6.0f, 0.5f, 6.0f);
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform2.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform2.GetModelMatrix()))));
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform2.GetModelMatrix());
	_shaderProgram.SetUniformf("LightPosition", glm::vec3(-5.0f, 5.0f, 5.0f));
	_shaderProgram.SetUniformf("LightColor", glm::vec3(1.0f, 1.0f, 1.0f));
	_shaderProgram.SetUniformf("CameraPosition", _camera.GetPosition());

	_shaderProgram.SetUniformi("DiffuseTexture1", 0);

	/////
	glActiveTexture(GL_TEXTURE0);
	_cubeBaseTexture.Bind();

	_mesh.Draw(GL_TRIANGLES);

	glActiveTexture(GL_TEXTURE0);
	_cubeBaseTexture.Unbind();
	////

	// Intercambiar los buffers (el que se estaba rendereando con el que se estaba
	// mostrando).
	glutSwapBuffers();
}

void Idle()
{
	// Cuando OpenGL entra en modo de reposo 
	// (para guardar bateria, por ejemplo)
	// le decimos que vuelva a dibujar ->
	// Vuelve a mandar a llamar GameLoop
	glutPostRedisplay();
}

void ReshapeWindow(int width, int height)
{
	glViewport(0, 0, width, height);
	_camera.SetPerspective(1.0f, 1000.0f, 60.0f, (float)width / (float)height);
}

int main(int argc, char* argv[])
{

	// Inicializamos freeglut. 
	// Freeglut se encarga de generar y manejar ventanas.
	// Utilizamos freeglut para crear una ventana donde vamos a dibujar.
	glutInit(&argc, argv);
	// Tenemos que informar que queremos trabajar con el pipeline
	// programable (OpenGL moderno).
	glutInitContextProfile(GLUT_CORE_PROFILE);
	// Freeglut nos permite configurar eventos que ocurren en la ventana.
	// Un evento que nos interesa es cuando alguien cierra la ventana.
	// En este caso, simplemente dejamos de renderear y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	// Configuramos el framebuffer. En este caso estamos solicitando un buffer
	// de color true color RGBA, un buffer de profundidad y un segundo buffer 
	// para rendererar (evitamos parpadeos al renderear).
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	// Solicitamos una ventana de 400x400 pixeles.
	glutInitWindowSize(400, 400);
	// Creamos y abrimos la ventana con un título personalizado.
	glutCreateWindow("Hello World OpenGL");
	// Asociar una función de render. Esta función se mandará a llamar para 
	// dibujar un frame.
	glutDisplayFunc(MainLoop);
	// Asociamos una función para el cambio de resolución
	// de la ventana. Freeglut la va a mandar a llamar
	// cuando alguien cambie el tamaño de la venta.
	glutReshapeFunc(ReshapeWindow);
	// Asociamos la función que se mandará a llamar
	// cuando OpenGL entre en modo de reposo.
	glutIdleFunc(Idle);

	// Inicializamos GLEW. Esta librería se encarga de obtener el API
	// de OpenGL de nuestra tarjeta de video. SHAME ON YOU MICROSOFT.
	glewInit();

	// COnfigurar OpenGL. Este es el color por default del buffer de color
	// en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
	// Ademas de solicitar el buffer de profundidad, tenemos
	// que decirle a OpenGL que lo queremos activo
	glEnable(GL_DEPTH_TEST);
	// Activamos el borrado de caras traseras.
	// Ahora todos los triangulos que dibujemos deben estar en CCW
	glEnable(GL_CULL_FACE);
	// No dibujar las caras traseras de las geometrías.
	glCullFace(GL_BACK);

	std::cout << glGetString(GL_VERSION) << std::endl;

	//inicializamos Devil
	ilInit();

	//cambia el punto de origen
	ilEnable(IL_ORIGIN_SET);

	//configurar el punto de origen en la esquina inferior izquierda
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);


	// Configurar la memoria que la aplicación va a necesitar.
	Initialize();



	// Iniciamos la aplicacion gráfica. El main se pausará en estea línea
	// hasta que se cierre la ventana de OpenGL.
	glutMainLoop();

	return 0;
}