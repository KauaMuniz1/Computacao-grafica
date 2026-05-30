#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h> 

void criar_quadrados(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, float r,float g, float b ){
    glColor3f(r,g,b);
    glBegin(GL_QUADS);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);

    glEnd();
        
}

void criar_triangulos(int x1, int y1, int x2, int y2, int x3, int y3, float r, float g, float b){
    glColor3f(r,g,b);
    glBegin(GL_TRIANGLES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);

    glEnd();
}

void criar_linhas(int x1, int y1, int x2, int y2, float r,float g,float b ){
    glColor3f(r,g,b);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
   

    glEnd();
        
}


void display(void) {
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Define a cor de fundo da cena (cor
                                         // usada para limpar o buffer de cor)
  glClear(GL_COLOR_BUFFER_BIT);  // Inicializa o buffer de cores antes de ele
                                 // ser alterado

  glMatrixMode(GL_MODELVIEW);  // Informa que as operações seguintes serão
                               // executadas na matrix modelview
  
  glLoadIdentity();            // Carrega a matriz identidade


  glPushMatrix(); 
    criar_triangulos(-100, 200, -150, 70, -50, 70, 0.61, 0, 1); // criando o triangulo que forma a casa
  glPopMatrix();


  glPushMatrix();
    criar_quadrados(-150,70, -50, 70, -50, -100, -150, -100,    0, 0, 1); //criando o quadrado em baixo do triangulo
  glPopMatrix();


  glPushMatrix();
    criar_quadrados(-125, -100, -125, -15, -75, -15, -75, -100, 0, 0, 0); // criando a porta da casa
  glPopMatrix();

  glPushMatrix();
    criar_quadrados(-115, -60, -110, -60, -110, -65, -115, -65,  1, 1, 1); // criando a maçaneta
  glPopMatrix();

  glPushMatrix();
    criar_quadrados(-100,200,  200, 200,  250, 70, -50, 70, 1, 0, 1); // criando o teto do lado do triangulo
  glPopMatrix();

  glPushMatrix();
    criar_quadrados(250, 70,   250, -100,   -50, -100,    -50, 70,    0,1,0); //criando o lado da casa (XD)
   glPopMatrix(); 

  glPushMatrix();
    criar_quadrados(-125, -100,   -75, -100,  -85, -150,   -145,  -150,   1, 0, 0);  //criando a calçada
  glPopMatrix();

  glPushMatrix();
    criar_quadrados(200, -20,    160, -20,   160, -50, 200, -50, 0, 1, 1 ); //criando janela da direita
  glPopMatrix();

  glPushMatrix();
    criar_quadrados(0, -20,   40, -20,   40, -50,   0, -50,    0, 1, 1); //criando a janela da esquerda
  glPopMatrix();

  glPushMatrix();
    criar_linhas(160, -35,  200, -35,  1,1,0); //linha horizontal da janela direita
  glPopMatrix();

  glPushMatrix();
    criar_linhas(180,-50,   180, -20,   1,1,0); //linha vertical da janela direita
  glPopMatrix();

  glPushMatrix();
    criar_linhas(0,  -35,  40, -35,   1, 1, 0); // linha horizontal da janela esquetda;
  glPopMatrix();

  glPushMatrix();
    criar_linhas(20, -20,   20, -50,   1, 1, 0);
  glPopMatrix();




  glutSwapBuffers();

    
}



void time_callback(int){
    glutPostRedisplay();
    glutTimerFunc(1000/60, time_callback,0); // chamando a funçao de novo infinitamente (LOL)
}


void resize(GLsizei w, GLsizei h){
  if (h == 0) h = 1;

  printf("Tam. janela: (%i,%i)\n", w, h);
  glViewport(0,0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-400, 400, -400, 400);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}


int main(int argc, char *argv[]){
    glutInit(&argc, argv);  // Inicializa a OpenGL
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(0,0);
    glutCreateWindow(
        "Exemplo da casa");
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutTimerFunc(0, time_callback, 0);
    glutMainLoop();
  
    return 0;
        
}