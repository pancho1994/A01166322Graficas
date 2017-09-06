/************************************************
Materia: Graficas Computacionales
Fecha: 06 de Septiembre del 2017
Autor: A01166322 Francisco Villafranca
************************************************/

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>

//lalalala batman
//Identificador del manager de VBO para un conjunto de vertices.
GLuint vao;

void Initialize()
{
	//vamos a crear una lista que almacena posiciones en 2 dimensiones de un triangulo.
	//esto es en CPU y RAM.
	std::vector<glm::vec2> positions;
	positions.push_back(glm::vec2(-0.95f, 0.30f));
	positions.push_back(glm::vec2(-0.47f, 0.15f));
	positions.push_back(glm::vec2(0.0f, 1.0f));
	positions.push_back(glm::vec2(0.0f, 0.5f));
	positions.push_back(glm::vec2(0.95f, 0.30f));
	positions.push_back(glm::vec2(0.47f, 0.15f));
	positions.push_back(glm::vec2(0.58f, -0.80f));
	positions.push_back(glm::vec2(0.29f, -0.40f));
	positions.push_back(glm::vec2(-0.58f, -0.80f));
	positions.push_back(glm::vec2(-0.29f, -0.40f));
	positions.push_back(glm::vec2(-0.95f, 0.30f));
	positions.push_back(glm::vec2(-0.95f, 0.30f));
	positions.push_back(glm::vec2(0.0f, 1.0f));
	positions.push_back(glm::vec2(-0.47f, 0.15f));
	positions.push_back(glm::vec2(-0.29f, -0.40f));
	
	
	
	
	
	
	

	//vamos a crear una lista para almacenar colores RGB
	//Esta lista esta en CPu y RAM
	std::vector<glm::vec3> colors;
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	

	//Creamos un vertex array object y almacenamos el id en la variable vao.
	//-este es el manager.
	glGenVertexArrays(1, &vao);
	//le decimos a opengl que queremos utilizar el manager;
	//Todos los VBOs que creemos a partir de este punto y hasta que desactivemos este VAO, se van a asociar a este manager.
	glBindVertexArray(vao);

	//identificador del VBO de posiciones. Aqui lo vamos a almacenar.
	GLuint positionsVBO;
	//creamos un VBO y almacenamos el identificador en la variable positionsVBO.
	glGenBuffers(1, &positionsVBO);
	//Le decimos a opengl que lo queremos utilizar como un atributo.
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
	//Asignamos los datos al buffer y los mandamos a la tarjeta de video.
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * positions.size(), positions.data(), GL_STATIC_DRAW);
	//Quiero activar el atributo con indice 0 en la tarjeta de video
	glEnableVertexAttribArray(0);
	//configuramos el atributo con indice 0 en la tarjeta de video.
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	//En este momento desactivamos el uso del VBO de posiciones.
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLuint colorsVBO;
	glGenBuffers(1, &colorsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, colorsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * colors.size(), colors.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//ya no quiero utilizar el vao. ya no se asociaran mas VBOs a este VAO.
	glBindVertexArray(0);
}

void MainLoop()
{
	//Borramos el buffer de color y profundidad siempre al inicio de un nuevo frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//paso 1 no lo podemos hacer aun


	//paso 2 activar un VAO 
	glBindVertexArray(vao);

	//paso 3 dibujamos
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 14);

	//paso 4 desactivamos el VAO
	glBindVertexArray(0);

	//paso 5 aun no lo podemos hacer



	glutSwapBuffers();

}

using namespace std;




int main(int argc, char* argv[])
{
	//Inicializamos freeglut.
	//Freeglut se encarga de generar y manejar ventanas.
	//Utilizamos Freeglut para crear una ventana donde vamos a dibujar
	glutInit(&argc, argv);
	//Tenemos que informar que queremos trabajar con el pipeline moderno programable
	glutInitContextProfile(GLUT_CORE_PROFILE);
	//Freeglut nos permite configurar eventos que ocurren en la ventana.
	//Un evento que nos interesa es cuando alguien cierra la ventana.
	//En este caso, simplemente dejamos de renderear y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	//Configuramos el framebuffer. en este caso estamos solicitando un uffer
	//de color true color RGBA, un buffer de profundidad y un segundo buffer para
	//renderear (evitamos parpadeos al renderear)
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	//Solicitamos una ventana de 400 * 400 pixeles.
	glutInitWindowSize(400, 400);
	//Creamos y abrimos la ventana con titulo personalizado
	glutCreateWindow("Hello world OpenGL");

	glutDisplayFunc(MainLoop);

	//Inicializamos GLEW. Esta libreria se encarga de obtener el appi de openGL de nuestra tarjeta de video.
	//shame on you microsoft.
	glewInit();
	//Configurar OpenGL. Este es el color por default del buffer color
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);

	//configurar la memoria que la aplicacion va a necesitar.
	Initialize();

	//Iniciamos la aplicacion grafica. el main se pausara en esta linea
	//
	//
	glutMainLoop();






	return 0;
}