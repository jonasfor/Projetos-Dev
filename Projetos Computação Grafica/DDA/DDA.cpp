/////////////////////////////////////////////////////////////////      
// DDA.cpp
//
// This program implements the DDA line rasterizer. The raster is
// simulated by the OpenGL window.
//
// Sumanta Guha.
///////////////////////////////////////////////////////////////// 

#include <cstdlib>
#include <iostream>
#include <stdio.h>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

using namespace std;
int step;
GLdouble modelview[16]; //matriz modelview
GLdouble projection[16]; //matriz projecao
/*
    Dados do vetor viewport:
    viewport[0]=x
    viewport[1]=y
    viewport[2]=width
    viewport[3]=height
*/
GLint viewport[4];
//variaveis utilizadas para pegar as coordenadas do mouse
GLfloat winX, winY, winZ;
GLdouble posX, posY, posZ;
GLdouble posX2, posY2, posZ2;

int flag;
// Draw a pixel as a point.
void pickPixel(int x, int y)
{
   glBegin(GL_POINTS);
      glVertex2i(x, y);
   glEnd();
}

// Round a float to a nearest integer.
int round(float z)
{
	 int y;
     y = z > 0.0 ? int(z + 0.5) : int(z - 0.5);
	 return y;
}

// DDA line rasterizer.
void DDA(int i1, int j1, int i2, int j2) // Assume i2 > i1.
{
	int aux;
	if(flag==0){
		flag=1;
		posX2=posX;
		posY2=posY;
		step=0;
	}
	else{
		flag=0;
		posX2=posX;
		posY2=posY;
		step=1;
	}
	if (i1>i2){
		aux=i1;
		i1=i2;
		i2=aux;
		aux=j1;
		j1=j2;
		j2=aux;
	}
	if(step!=1){
   float y = j1;
   float m = float(j2 - j1)/(i2 - i1); // Assume -1 <= m <= 1.
   for(int x = i1; x <= i2; x++)
   {
      pickPixel(x, round(y));
	  y += m;
   }
	}
}

// Drawing routine.
void drawScene(void)
{  
   glClear(GL_COLOR_BUFFER_BIT);

   glColor3f(0.0, 0.0, 0.0);

   glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
   glGetDoublev( GL_PROJECTION_MATRIX, projection );
   glGetIntegerv( GL_VIEWPORT, viewport );


   if((posX!=0)&&(posY!=0))
   	DDA(posX, posY, posX2, posY2);
	
   
   
   glFlush();
}

// Initialization routine.
void setup(void) 
{
   glClearColor(1.0, 1.0, 1.0, 0.0); 
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
   glViewport(0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   // The height/width of the ortho-box match that of the OpenGL window,
   // resulting in a point-to-pixel correspondence.
   gluOrtho2D(0.0, 500.0, 0.0, 500.0);
   
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
   switch(key) 
   {
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

void mouse(int button, int state, int x, int y){
    //caso botao do mouse seja pressionado
    if (state == GLUT_DOWN){
        //passando para coordenadas do mundo real
        winX = (float)x; //passando o valor de x por cast, pois a variavel winX e' do tipo GLfloat
        winY = (float)viewport[3] - (float)y; //viewport[3] e y sao inteiros, por isso sao passados por cast p/ winY que e' GLfloat
        //funcao que pega as coordenadas de x, y
        gluUnProject( winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);
      	printf("x %f\n", posX);
      	printf("y %f\n", posY);
      	printf("z %f\n", posZ);
        glutPostRedisplay();
    }
}
// Main routine.
int main(int argc, char **argv) 
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100); 
   glutCreateWindow("DDA.cpp");
   setup(); 
   glutDisplayFunc(drawScene); 
   glutReshapeFunc(resize);  
   glutKeyboardFunc(keyInput);
   glutMouseFunc(mouse);
   glutMainLoop(); 

   return 0;  
}
