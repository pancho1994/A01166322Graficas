/************************************************
Materia: Graficas Computacionales
Fecha: 04 de Octubre del 2017
Autor: A01166322 Francisco Villafranca
************************************************/

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include "InputFile.h"
#include <vector>


// Identificador del manager de VBOs para un conjunto de vertices.
GLuint vao;
// Identificador del manager de Shaders (Shader program).
GLuint shaderProgram;

// Función que va a inicializar toda la memoria del programa.
void Initialize()
{
	// Vamos a crear una lista que va a almacenar las posiciones
	// en 2 dimensiones de un triángulo.
	// Esto es en CPU y RAM.
	std::vector<glm::vec2> positions;
	positions.push_back(glm::vec2(-1.0f, -1.0f));
	positions.push_back(glm::vec2(1.0f, -1.0f));
	positions.push_back(glm::vec2(0.0f, 1.0f));

	// Vamos a crear una lista para almacenar colores RGB
	// Esta lista está en CPU y RAM
	std::vector<glm::vec3> colors;
	// RGB -> Rojo
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	// RGB -> Verde
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	// RGB -> Azul
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));

	// Creamos un VAO y almacenamos el id en la variable vao.
	// Este es el manager de VBOs
	glGenVertexArrays(1, &vao);
	// Le decimos a OpenGL que queremos utilizar el manager.
	// Todos los VBOs que creemos a partir de este punto y hasta
	// que desactivemos este VAO, se van a asociar a este manager.
	glBindVertexArray(vao);

	// Identificador del VBO de posiciones. Aqui lo vamos a almacenar.
	GLuint positionsVBO;
	// Creamos un VBO y almacenamos el id en la variable positionsVBO
	glGenBuffers(1, &positionsVBO);
	// Le decimos a OpenGL que lo queremos utilizar como un atributo.
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
	// Asignamos los datos al buffer y los mandamos a la tarjeta de video.
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * positions.size(),
		positions.data(), GL_STATIC_DRAW);
	// Quiero activar el atributo con indice 0 en la tarjeta de video
	glEnableVertexAttribArray(0);
	// Configuramos el atributo con indice 0 en la tarjeta de video.
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	// Desactivamos el uso del VBO de posiciones
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLuint colorsVBO;
	glGenBuffers(1, &colorsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, colorsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * colors.size(),
		colors.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Ya no quiero utilizar el VAO. Ya no se asociarán más VBOs a este VAO
	glBindVertexArray(0);

	InputFile ifile;
	//leemos el codigo fuente con la clase auxiliar inputFile
	ifile.Read("Default.vert");
	//Obtenemos los elementos leidos y los almacenamos en la variable vertexSource
	std::string vertexSource = ifile.GetContents();
	//conversion de string a char* OBLIGATORIA
	const GLchar *vertexSource_c = (const GLchar*)vertexSource.c_str();
	GLuint vertexShaderHandle = glCreateShader(GL_VERTEX_SHADER);
	//le mandamos el codigo fuente que leimos previamente a OpenGL
	glShaderSource(vertexShaderHandle, 1, &vertexSource_c, nullptr);
	//Le pedimos que lo compile
	glCompileShader(vertexShaderHandle);

	GLint vertexShaderCompileSuccess = 0;
	glGetShaderiv(vertexShaderHandle, GL_COMPILE_STATUS, &vertexShaderCompileSuccess);
	if (vertexShaderCompileSuccess == GL_FALSE)
	{
		GLint logLength = 0;
		glGetShaderiv(vertexShaderHandle, GL_INFO_LOG_LENGTH, &logLength);
		if (logLength > 0)
		{
			std::vector<GLchar> compileLog(logLength);
			glGetShaderInfoLog(vertexShaderHandle, logLength, &logLength, &compileLog[0]);

			for (int i = 0; i < logLength; i++) {
				std::cout << compileLog[i];
			}
			std::cout << std::endl;
		}
		std::cout << "Shader Default.vert did not compiled" << std::endl;
	}


	//leemos el codigo fuente con la clase auxiliar inputFile
	ifile.Read("Default.frag");
	//Obtenemos los elementos leidos y los almacenamos en la variable vertexSource
	std::string fragmentSource = ifile.GetContents();
	//conversion de string a char* OBLIGATORIA
	const GLchar *fragmentSource_c = (const GLchar*)fragmentSource.c_str();
	GLuint fragmentShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
	//le mandamos el codigo fuente que leimos previamente a OpenGL
	glShaderSource(fragmentShaderHandle, 1, &fragmentSource_c, nullptr);
	//Le pedimos que lo compile
	glCompileShader(fragmentShaderHandle);

	//Creando el manager de los shaders
	shaderProgram = glCreateProgram();
	//Decimos que va a administrar el shader
	glAttachShader(shaderProgram, vertexShaderHandle);
	glAttachShader(shaderProgram, fragmentShaderHandle);
	//Se hacen los bind
	glBindAttribLocation(shaderProgram, 0, "VertexPosition");
	glBindAttribLocation(shaderProgram, 1, "VertexColor");
	//Verificamos que las etapas de los shaders pueden trabajar en conjunto
	glLinkProgram(shaderProgram);

}

void MainLoop()
{
	// Borramos el buffer de color y profundidad siempre al inicio de un nuevo frame.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Activar el shader manager.
	glUseProgram(shaderProgram);
	// Paso 2: Activar un VAO
	glBindVertexArray(vao);
	// Paso 3: Dibujamos
	glDrawArrays(GL_TRIANGLES, 0, 3);
	// Paso 4: Desactivamos el VAO
	glBindVertexArray(0);
	// Desactivamos el shader manager.
	glUseProgram(0);

	// Intercambiar los buffers (el que se estaba rendereando con el que se estaba
	// mostrando).
	glutSwapBuffers();
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

	// Inicializamos GLEW. Esta librería se encarga de obtener el API
	// de OpenGL de nuestra tarjeta de video. SHAME ON YOU MICROSOFT.
	glewInit();

	// COnfigurar OpenGL. Este es el color por default del buffer de color
	// en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);

	// Configurar la memoria que la aplicación va a necesitar.
	Initialize();

	// Iniciamos la aplicacion gráfica. El main se pausará en estea línea
	// hasta que se cierre la ventana de OpenGL.
	glutMainLoop();

	return 0;
}