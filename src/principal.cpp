#include "freeglut.h"
#include "ETSIDI.h"
#include "inicio.h"
#include "ajedrez.h"
#include "ajedrez2.h"
#include "ajedrezbot.h"
#include <cstdlib>
#include <stdlib.h>

using namespace std;

Inicio inicio;
Inicio final;
Ajedrez ajedrez;
Ajedrez2 ajedrez2;
Ajedrezbot ajedrezbot;
int start = 0;

//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla
void onMouse(int button, int state, int x, int y); // Declaración de onMouse()

int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	
	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	//glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(onMouse);

	//POSIBLE INICIALIZACION
		
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}

void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	//funciones de dibujo
	if (start == 1) ajedrez.dibuja(); //dibuja el tablero y las piezas
	else if (start == 2) ajedrez2.dibuja();//4x4
	else if (start == 3) ajedrezbot.dibuja();//4x4
	else if (start == 4) { final.dibuja_final(); cout << endl << "PULSE LA TECLA ESCAPE PARA ABANDONAR EL JUEGO" << endl; }//dibuja pantalla fin partida
	else inicio.dibuja_portada();

	

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	switch (key)
	{
		//START
	case 'A':
		if (start == 0)
		{
			start = 1;
			stopMusica();
		}
		break;
	case 'B':
		if (start == 0)
		{
			start = 2;
			stopMusica();
		}
		break;
	case 'a':
		if (start == 0)
		{
			start = 1;
			stopMusica();
		}
		break;
	case 'b':
		if (start == 0)
		{
			start = 2;
			stopMusica();
		}
		break;
	case '3':
		if (start == 0)
		{
			start = 3;
			stopMusica();
		}
		break;
	case 27:
		if (start != 0 && start != 4)
		{
			ajedrez.tablero.limpiar_Tablero();
			ajedrez2.tablero.limpiar_Tablero();
			ajedrezbot.tablero.limpiar_Tablero();
			start = 0;
			ajedrez = Ajedrez();
			ajedrez2 = Ajedrez2();
			ajedrezbot = Ajedrezbot();
		}
		if (start == 4)
		{
			
			exit(0);
		}
		break;
	case 'P':
		if (start != 0 && start != 4)
		{
			start = 0;
		}
		break;
	case 'p':
		if (start != 0 && start != 4)
		{
			start = 0;
		}
		break;

	default:
		break;

	case 'F':
		if (start == 1 || start == 2)
		{
			start = 4;
		}
		break;
	case 'f':
		if (start == 1 || start == 2)
		{
			start = 4;
		}
		break;
	}
	glutPostRedisplay();
}

void onMouse(int button, int state, int x, int y)
{
	bool down = (state == GLUT_DOWN);
	if (button == GLUT_LEFT_BUTTON)
	{
		if (start == 1)
		{
			ajedrez.detectaClick(x, y, button, down);
			glutPostRedisplay();
		}
		if (start == 2)
		{
			ajedrez2.detectaClick(x, y, button, down);
			glutPostRedisplay();
		}
	}
		
}



