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

}
// Draw a pixel as a point.
void pickPixel(int x, int y);
int valor(){
  dx=x2-x1;
  dy=y2-y1;
  d=2*(dy-dx);
  cout<<"d : "<<d<<"\n";
  incE=2*dy;
  incNE=2*(dy-dx);
  incN=2*dx;
  incNw=2*(dx-dy);
  incW=2*(-dy);
  incSW=2*(-(dy-dx));
  incS=2*(-dx);
  incSE=2*(-(dx-dy));

  x=x1; y=y1;
  pickPixell(x,y);
  while(x<x2){
    if(d<=0){
      d=d+incE;
      x++;
    }
    else{
      d=d+incNE;
      x++; y++;
    }
    pickPixell(x,y);
  }

  while(x<x2){
    if(d<=0){
      d=d+incN;
      x++;
    }
    else{
      d=d+incNw;
      x++; y++;
    }
    pickPixell(x,y);
  }
while(x>x2){
    if(d<=0){
      d=d+incS;
      x++;
    }
    else{
      d=d+incSW;
      x++; y++;
    }
    pickPixell(x,y);
  }
while(x>x2){
    if(d<=0){
      d=d+incS;
      x++;
    }
    else{
      d=d+incSE;
      x++; y++;
    }
    pickPixell(x,y);
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
    
      pickPixel(x2,y2);
   
   
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
void pickPixel(int x, int y)
{
   glBegin(GL_LINES);
   glColor3f(1,0,0);
   	glVertex3f(500,250, 0);
   	glVertex3f(0,250, 0);
   	glVertex3f(250,500, 0);
   	glVertex3f(250,0, 0);
   	glVertex3f(0,500, 0);
   	glVertex3f(500,0, 0);
   	glVertex3f(500,500, 0);
   	glVertex3f(0,0, 0);
   glEnd();
 	glColor3f(0,0,0);
   glBegin(GL_LINES);
   	  glVertex2i(250, 250);
      glVertex2i(x, y);
   glEnd();
}
