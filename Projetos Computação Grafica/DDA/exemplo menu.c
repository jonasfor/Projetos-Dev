#include <GL/glut.h> 
static int window;
static int menu_id;
static int submenu_id;
static int value = 0; 
void menu(int num){
  if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
  }
  glutPostRedisplay();
} 
void printStrings(float posStrX, float posStrY, const char *str){
    //mudando cor da linha para verde
    glColor3f (0.0, 1.0, 0.0);
    //posicionando string na tela
    glRasterPos2f(posStrX, posStrY);
 
    //String exibida na tela
    char* p = (char*) str; //atribui da variavel *p
 
    while (*p != '\0') {//percorre string ate o final
        //funcao da glut que imprime char por char na tela
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*p++);
    }
}
void createMenu(void){     submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("SBresengham", 2);
     glutAddMenuEntry("Rasterizacao 0", 4);
    glutAddMenuEntry("DDA", 3);
    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Limpar", 1);
    glutAddSubMenu("Algoritimos", submenu_id);
    glutAddMenuEntry("Quit", 0);     glutAttachMenu(GLUT_RIGHT_BUTTON);
} 
void display(void){
  glClear(GL_COLOR_BUFFER_BIT);   
   printStrings(-0.5,  0.5, "Clique com o botao direito ");
   printStrings(-0.5,  0, "e escolha as opcoes do menu ");
  if(value == 1){
    return; //glutPostRedisplay();
  }else if(value == 2){
    system("g++ Bresenham.cpp -o exe -lm -lGL -lGLU -lglut");
    system("./exe");
    system("rm exe");
    value=1;
  }else if(value == 3){
    system("g++ DDA.cpp -o exe -lm -lGL -lGLU -lglut");
    system("./exe");
    system("rm exe");
    value=1;
  }else if(value == 4){
    system("g++ RasterizacaoCIRCUS.cpp -o exe -lm -lGL -lGLU -lglut");
    system("./exe");
    system("rm exe");
    value=1;
  }

  glFlush();
} 
int main(int argc, char **argv){     glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(500,100);
    glutInitWindowPosition(100,100);
    window = glutCreateWindow("Menus and Submenus CUT");
    createMenu();     glClearColor(0.0,0.0,0.0,0.0);
    glutDisplayFunc(display);     glutMainLoop();
    return EXIT_SUCCESS;
}