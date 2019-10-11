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
int x1,x2,y1,y2,dx,dy, incE, incNE, incN, incS,incSE, incNw,incW ,incSW ,d,x,y;
int flag;

void pickPixell(int x, int y)
{
  glBegin(GL_POINTS);
    glVertex2i(x,y);
  glEnd();
}
// Draw a pixel as a point.

void ponto_ciculo(int x, int y){
  pickPixell(x,y,valor);
  pickPixell(y,x,valor);
  pickPixell(y,-x,valor);
  pickPixell(x,-y,valor);
  pickPixell(-x,-y,valor);
  pickPixell(-y,-x,valor);
  pickPixell(-y,x,valor);
  pickPixell(-x,y,valor);
}

void valor(int raio){
  int x=0;
  int y=raio;
  double d=5/4-raio;
  ponto_ciculo(x,y);
  while(y<x){
    if(d<0){
      d+=2.0 * x+3.0;
    }
    else{
      d+=2.0 * (x-y)+5;
      y--;
    }
    x++;
    ponto_ciculo(x,y);

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
      x1=250; y1=250; 
   

      x2=posX; y2=posY; 
    
   valor(y2);
   
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
   glutCreateWindow("bresenham.cpp");
   setup(); 
   glutDisplayFunc(drawScene); 
   glutReshapeFunc(resize);  
   glutKeyboardFunc(keyInput);
   glutMouseFunc(mouse);
   glutMainLoop(); 

   return 0;  
}
