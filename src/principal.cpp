#include "freeglut.h"
#include "ETSIDI.h"
#include "inicio.h"
#include "ajedrez.h"
#include "ajedrez2.h"

Inicio inicio;
Ajedrez ajedrez;
Ajedrez2 ajedrez2;
int start = 0;

//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
//void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
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
	else inicio.dibuja();

	

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
	case 'B':
		if (start == 0)
		{
			start = 2;
			stopMusica();
		}
	default:
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
/*
void onMouse(int button, int state, int x, int y)
{
	ajedrez.detectaClick(button,  state,  x,  y);
}*/



/*void OnTimer(int value)
{
//poner aqui el código de animacion
// 
	//no borrar estas lineas
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();
}*/

