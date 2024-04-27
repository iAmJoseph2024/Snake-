/*Juego Snake Proyecto LPOO*/

#include <iostream>
#include <GL/glut.h> //Libreria para OpenGL
#include <vector> 
using namespace std;

//Variables globales
const int tamanio = 12; // Tamaño de la matriz
const int velocidad = 50; //Velocidad que va a tener la serpiente 

class Snake //Clase de la serpiente con todas sus caracteristicas
{
private: 
    vector<pair<int, int>> segmentos;
    int direccion; // Direccion de la serpiente
public:
    //Constructor
    Snake()
    {
        segmentos.push_back(make_pair(tamanio / 2, tamanio / 2)); //Donde va a comenzar la serpiente
    } 

    void movimientoSnake()
    {
        int posicionX = segmentos.front().first;
        int posicionY = segmentos.front().second;

        switch (direccion)
        {
            case 1: //derecha
                posicionX++;
                break;

            case 2: //izquierda
                posicionX--;
                break;

            case 3: //arriba
                posicionY++;
                break;

            case 4: //abajo
                posicionY--;
                break;
        }

        //Esto para colocar la nueva posicion de la serpiente en la cabeza
        segmentos.insert(segmentos.begin(), make_pair(posicionX, posicionY)); 

        //Eliminar el ultimo segmento de la serpiente
        segmentos.pop_back();
    }

    //Para que el movimiento de la serpiente no le lleve la contraria, o sea, que no se equivoque de direccion
    void setDireccion(int dir)
    {
        if ((dir == 1 && direccion != 2) || (dir == 2 && direccion != 1) || (dir == 3 && direccion != 4) || (dir == 4 && direccion != 3))
        {
            direccion = dir;
        }
    }

    //Funcion para dibujar a la serpiente
    void dibujarSerpiente()
    {
        //El color que va a tener
        glColor3f(0.0, 1.0, 0.0); //En este caso es color verde
        glPointSize(4.0); //Tamanio de la serpiente

        glBegin(GL_POINTS);
        for (const auto& segmento : segmentos)
        {
            glVertex2i(segmento.first, segmento.second);
        }

        glEnd();
    }
};

Snake serpiente; //Personaje de la serpiente

void myDisplay() //Funcion para poder desplegar la ventana
{  
    glClear(GL_COLOR_BUFFER_BIT);
    serpiente.dibujarSerpiente();
    glutSwapBuffers();
}

void tiempo(int valor)
{
    serpiente.movimientoSnake();
    glutPostRedisplay();
    glutTimerFunc(velocidad, tiempo, 0);
}

void teclasSerpiente(unsigned char teclado, int x, int y) {
    switch (teclado) {
    case 'w':
        serpiente.setDireccion(3); // Arriba
        break;
    case 'a':
        serpiente.setDireccion(2); // Izquierda
        break;
    case 's':
        serpiente.setDireccion(4); // Abajo
        break;
    case 'd':
        serpiente.setDireccion(1); // Derecha
        break;
    }
}

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
    glClearColor(0.196f, 0.5686f, 0.7333f, 0.0f);
    /*El primero es R, segundo G y tercero B
        Rango de 0.0 a 1.0, donde 0.0 es no color y 1.0 intencidad completa.
    Si quieren un color que sea la combinacion de todos se hace (R)/255
        Donde R es el valor de rojo deseado (codigo RGB). Esto se hace para todos los valores (G,B)
    */

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