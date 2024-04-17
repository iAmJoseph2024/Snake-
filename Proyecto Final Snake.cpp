/*Juego Snake Proyecto LPOO*/

#include <iostream>
#include <GL/glut.h>
#include <math.h>


using namespace std; 
 
	void myInit() { //Funcion para establecer el fondo del menu
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	}

	   
	void start() { //Funcion para establecer la vista de la pantalla del start
		glClear(GL_COLOR_BUFFER_BIT);

		glEnd();

	} 

	void myDisplay() {  //Funcion para poder desplegar la ventana
		glClear(GL_COLOR_BUFFER_BIT);

		glFlush();
	} 

	void myMenu(int id) { //Funcion para determinar acciones dentro de la ventana 
		cout << "kk" << id;
		switch (id)
		{
		case 1:
			start(); 
			break;

		case 2:
			exit(0);
			break;
		}
	}
const int tamanio = 12; // Tamaño de la matriz

// Función para hacer el muro con matrices 
void dibujarMuro() {

    // Borrar el buffer de color
    glClear(GL_COLOR_BUFFER_BIT);

    // Establecer el color de la línea para cada parte de los 
    glColor3f(1.0f, 1.0f, 1.0f); //Blanco

    // Dibujar líneas verticales para los bordes 
    glBegin(GL_LINES);
    for (int i = 0; i <= tamanio; i++) { //Columnas
        glVertex2f(i, 0); 
        glVertex2f(i, tamanio);

        glVertex2f(0, i);
        glVertex2f(tamanio, i);
    }
    glEnd(); //Fin de las columnas

    // Intercambiar los buffers
    glutSwapBuffers();
}

// Función para inicializar OpenGL
void inicializarGl() {

    // Es para el color de fondo que va a tener
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    // Configurar la proyección ortográfica
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, tamanio, 0.0, tamanio, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    // Inicializar la libreria GLUT
    glutInit(&argc, argv);

    int menu_id; //variable para mandar a llamar el menu
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize(800, 500); 
		glutInitWindowPosition(100, 100);
		glutCreateWindow("Snake");
		glutDisplayFunc(myDisplay);
		menu_id = glutCreateMenu(myMenu);
		glutAddMenuEntry("Start", 1); 
		glutAddMenuEntry("Exit", 2);
		glutAttachMenu(GLUT_LEFT_BUTTON); //Funcion para hacer aparecer el menu con click izquierdo de mouse (se cambiara para la creacion final del menu)

		myInit(); //Mandar a llamar la funcion myInit e inicializar el fondo

    // Esto es para que se pueda ver una ventana para el juego
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    // Crear la ventana que se va a ver a la hora de que corra el programa
    glutInitWindowSize(600, 600); // Cuantos pixeles quiere que tenga el juego
    glutInitWindowPosition(100, 100); // Posición de la ventana
    glutCreateWindow("Serpiente al ataque");

    // Inicializar OpenGL
    inicializarGl();

    // Establecer la función para poder ver el mapa
    glutDisplayFunc(dibujarMuro);

    // Iniciar el ciclo principa
    glutMainLoop();

    

    return 0;
}
