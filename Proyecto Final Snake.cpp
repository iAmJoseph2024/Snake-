/*Juego Snake Proyecto LPOO*/

#include <iostream>
#include <GL/glut.h>

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