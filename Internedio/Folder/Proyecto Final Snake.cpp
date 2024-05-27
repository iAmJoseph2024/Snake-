/*Juego Snake Proyecto LPOO
Se ve como puntitos la serpiente y avansa sober las lineas del mapa*/

#include <iostream>
#include <GL/glut.h> //Libreria para OpenGL
#include <vector> 
#include <cstdlib> // Para rand()
#include <time.h>//Funcion tiempo para agarar semilla nueva
using namespace std;

//Variables globales
const int tamanio = 12; // Tama�o de la matriz
const int velocidad = 900; //Velocidad que va a tener la serpiente 

class Snake //Clase de la serpiente con todas sus caracteristicas
{
public:
    vector<pair<int, int>> segmentos;
    int direccion; // Direccion de la serpiente

    //Constructor
    Snake()
    {
        segmentos.push_back(make_pair(tamanio / 2, tamanio / 2)); //Donde va a comenzar la serpiente
    }
//Suma numeros para mover de posicion
    void movimientoSnake(bool crecer)
    {
        int posicionX = segmentos.front().first;
        int posicionY = segmentos.front().second;

        switch (direccion)
        {
        case 1: // Derecha
            posicionX++;
            break;

        case 2: // Izquierda
            posicionX--;
            break;

        case 3: // Arriba
            posicionY++;
            break;

        case 4: // Abajo
            posicionY--;
            break;
        }

      // Marca la posicion nueva de la cabesa
        segmentos.insert(segmentos.begin(), make_pair(posicionX, posicionY));

        // Quita el ultimo segmento si no crese
        if (!crecer) {
            segmentos.pop_back();
        }
    }

    //Para que el movimiento de la serpiente no le lleve la contraria, o sea, que no se equivoque de direccion
    void setDireccion(int dir) {
        if ((dir == 1 && direccion != 2) || (dir == 2 && direccion != 1) ||
            (dir == 3 && direccion != 4) || (dir == 4 && direccion != 3)) {
            direccion = dir;
        }
    }

    //Funcion para dibujar a la serpiente
    void dibujarSerpiente()
    {
        //El color que va a tener
        glColor3f(0.0, 0.0, 0.0); // Color serpiente
        glPointSize(10); //Tamanio de la serpiente

        glBegin(GL_POINTS);
        for (const auto& segmento : segmentos)
        {
            glVertex2i(segmento.first, segmento.second);
        }
    }

};

Snake serpiente; //Personaje de la serpiente

pair<int, int> comidaPos;

void generarComida() {
    srand(time(NULL));
    comidaPos.first = rand() % tamanio;
    comidaPos.second = rand() % tamanio;
}

void myDisplay() //Funcion para poder desplegar la ventana Menu
{
    glClear(GL_COLOR_BUFFER_BIT);

    glutSwapBuffers();
}

void tiempo(int valor)
{
    serpiente.movimientoSnake(false); // Para que no crezca

    // choque con de la serpiente
    for (size_t i = 1; i < serpiente.segmentos.size(); ++i) {
        if (serpiente.segmentos.front() == serpiente.segmentos[i]) {
            cout << " == Game Over==" << endl;
            exit(0);
        }
    }

    // choque con de la pared
    if (serpiente.segmentos.front().first < 0 || serpiente.segmentos.front().first >= tamanio ||
        serpiente.segmentos.front().second < 0 || serpiente.segmentos.front().second >= tamanio) {
        cout << "==Game Over==" << endl;
        exit(0);
    }

    // choque con de la comida
    if (serpiente.segmentos.front() == comidaPos) {
        serpiente.movimientoSnake(true); // Para que crezca

        generarComida(); // Genera nueva comida
    }

    glutPostRedisplay();
    glutTimerFunc(velocidad / serpiente.segmentos.size(), tiempo, 0); // Velocidad de acuerdo con tamanio
}


//Teclas con mayusculas
void teclasSerpiente(unsigned char teclado, int x, int y) {
    switch (teclado) {
    case 'w':
        serpiente.setDireccion(3); // Arriba
        break;
    case 'a':
        if (serpiente.direccion != 1 && serpiente.segmentos.front().first > 0)
            serpiente.setDireccion(2); // Izquierda
        break;
    case 's':
        serpiente.setDireccion(4); // Abajo
        break;
    case 'd':
        if (serpiente.direccion != 2 && serpiente.segmentos.front().first < tamanio - 1)
            serpiente.setDireccion(1); // Derecha
        break;
    case 'W':
        serpiente.setDireccion(3); // Arriba
        break;
    case 'A':
        if (serpiente.direccion != 1 && serpiente.segmentos.front().first > 0)
            serpiente.setDireccion(2); // Izquierda
        break;
    case 'S':
        serpiente.setDireccion(4); // Abajo
        break;
    case 'D':
        if (serpiente.direccion != 2 && serpiente.segmentos.front().first < tamanio - 1)
            serpiente.setDireccion(1); // Derecha
        break;
    }
}
//Es para el alt+F4
void Teclado_EXP(int Tecla, int x, int y)
{
    if (Tecla == GLUT_KEY_F4)
    {
        cout << "There is no hope. Nor will there be an escape. :)" << endl;
        exit(x);
    }

}

void myInit() { //Funcion para establecer el fondo del menu
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, tamanio, 0.0, tamanio); // Ajustado para que coincida con el tamaño de la ventana
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

// Funci�n para hacer el muro con matrices 
void dibujarMuro() {

    // Borrar el buffer de color
    glClear(GL_COLOR_BUFFER_BIT);

    // Establecer el color de la l�nea para cada parte de los 
    glColor3f(1.0f, 1.0f, 1.0f); //Blanco

    // Dibujar l�neas verticales para los bordes 
    glBegin(GL_LINES);
    for (int i = 0; i <= tamanio; i++) { //Columnas
        glVertex2f(i, 0);
        glVertex2f(i, tamanio);

        glVertex2f(0, i);
        glVertex2f(tamanio, i);
    }
    glEnd(); //Fin de las columnas

    serpiente.dibujarSerpiente();
    // Hace la comida
    glColor3f(0.50, 0.0, 0.100); // Color de la comida
    glPointSize(10);//Tamanio de la comida
    glBegin(GL_POINTS);
    glVertex2i(comidaPos.first, comidaPos.second); //Posicion de la comida
    glEnd();

    // Intercambiar los buffers
    glutSwapBuffers();
}

// Funci�n para inicializar OpenGL
void inicializarGl() {

    // Es para el color de fondo que va a tener el fondo del juego
    glClearColor(0.7647f, 0.9607f, 0.7294f, 0.0f);

    // Configurar la proyecci�n ortogr�fica
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
    glutInitDisplayMode(GL_DOUBLEBUFFER | GLUT_RGB);
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
    glutInitDisplayMode(GL_DOUBLEBUFFER | GLUT_RGB);

    // Crear la ventana que se va a ver a la hora de que corra el programa
    glutInitWindowSize(600, 600); // Cuantos pixeles quiere que tenga el juego
    glutInitWindowPosition(100, 100); // Posici�n de la ventana
    glutCreateWindow("Serpiente al ataque");

    // Inicializar OpenGL
    inicializarGl();

    // Establecer la funci�n para poder ver el mapa
    glutDisplayFunc(dibujarMuro);

    glutKeyboardFunc(teclasSerpiente);
    //Funcion para F4 
    glutSpecialFunc(Teclado_EXP);
    glutTimerFunc(0, tiempo, 0);

    generarComida(); // Genera la posicion inicial de la comida
    // Iniciar el ciclo principa
    glutMainLoop();

    return 0;
}
