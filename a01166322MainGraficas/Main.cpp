/************************************************

Materia: Graficas Computacionales
Fecha: 23 de Agosto del 2017
Autor: A01166322 Francisco Vil lafranca

************************************************/

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

void MainLoop()
{
	//borramos el buffer de color y profundidad siempre al inicio de un nuevo frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//WARNING ESTO ES OPENGL CLASICO Y NO LO VAMOS A VOLVER A USAR JAMAS
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-1.0f, -1.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, -1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.0f, 1.0f);
	glEnd();
	//FIN DEL WARNING

	glutSwapBuffers();
	
}

using namespace std;




int main(int argc, char* argv[])
{
	//Inicializamos freeglut.
	//Freeglut se encarga de generar y manejar ventanas.
	//Utilizamos Freeglut para crear una ventana donde vamos a dibujar
	glutInit(&argc, argv);
	//Tenemos que informar que queremos trabajar con el pipeline clasico y eso es OpenGL viejito
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
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
	//Iniciamos la aplicacion grafica. el main se pausara en esta linea
	//
	//
	glutMainLoop();






	return 0;
}