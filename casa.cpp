#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h> 

void criar_quadrados(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int r,int g, int b ){
    glColor3f(r,g,b);
    glBegin(GL_QUADS);
    glVertex2f(x1,y1);
    glVertex2f(x1,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);

    glEnd();
        
}

void criar_triangulos(int x1, int y1, int x2, int y2, int x3, int y3, int r, int g, int b){
    glColor3f(r,g,b);
    glBegin(GL_TRIANGLES);
    glVertex2f(x1,y1);
    glVertex2f(x1,y2);
    glVertex2f(x3,y3);

    glEnd();
}

void criar_linhas(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int r,int g, int b ){
    glColor3f(r,g,b);
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x1,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);

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

  
  glutSwapBuffers();
    
}



void time_callback(int){
    glutPostRedisplay();
    glutTimerFunc(1000/60, time_callback,0); // chamando a funçao de novo infinitamente (LOL)
}

void resize(GLsizei w, GLsizei h) {
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