#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

GLdouble pos_trem = 0;
int cam_view = 0;

void render_rails() {
    glColor3f(0.4, 0.2, 0.0);
    glPushMatrix();
    glScalef(200, 1, 1);
    glTranslatef(0, -6, 8);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glScalef(200, 1, 1);
    glTranslatef(0, -6, -8);
    glutSolidCube(1);
    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    render_rails();
    glPushMatrix();
    glTranslatef(pos_trem,0,0);
    glColor3f(0.25,0.25,0.25);

    //locomotiva
    glPushMatrix();
    glTranslatef(0,0,0);
    glColor3f(1,0,0);
    glScalef(30,10,15);
    glutSolidCube(1);

    glPopMatrix();


    //rodasLocomotiva parte de frente
    glPushMatrix();
    glTranslatef(15,0,0);
    glColor3f(0,0,0);
    //roda esquerda
    glPushMatrix();
    glTranslatef(0,-6,-7.5);

    glRotatef(90,0,0,1);
    glutSolidTorus(1,5,15,20);
    glPopMatrix();
    //roda direita
    glPushMatrix();
    glTranslatef(0,-6,7.5);
    glRotatef(90,0,0,1);
    glutSolidTorus(1,5,15,20);
    glPopMatrix();

    glPopMatrix();

    //rodasLocomotiva parte de tras
    glPushMatrix();
    glTranslatef(-15,0,0);
    glColor3f(0,0,0);
    //roda esquerda
    glPushMatrix();
    glTranslatef(0,-6,-7.5);
    glRotatef(90,0,0,1);
    glutSolidTorus(1,5,15,20);
    glPopMatrix();
    //roda direita
    glPushMatrix();
    glTranslatef(0,-6,7.5);
    glRotatef(90,0,0,1);
    glutSolidTorus(1,5,15,20);
    glPopMatrix();

    glPopMatrix();


    //vagao
    glPushMatrix();
    glTranslatef(-25,0,0);
    glColor3f(0,0,1);
    glScalef(20,8,15);
    glutSolidCube(1);
    glPopMatrix();


    //rodasVagaoParteDeFrente
    glPushMatrix();
    glTranslatef(-15,0,0);

    //rodaEsquerda
    glPushMatrix();
    glTranslatef(0,-6,-7.5);
    glColor3f(0,0,0);
    glRotatef(90,0,0,1);
    glutSolidTorus(1,5,15,20);
    glPopMatrix();

    //rodadireita
    glPushMatrix();
    glTranslatef(0,-6,7.5);
    glColor3f(0,0,0);
    glRotatef(90,0,0,1);
    glutSolidTorus(1,5,15,20);
    glPopMatrix();

    glPopMatrix();
    //rodasVagaoParteDeTras

    glPushMatrix();
    glTranslatef(-35,0,0);

    //rodaEsquerda
    glPushMatrix();
    glTranslatef(0,-6,-7.5);
    glColor3f(0,0,0);
    glRotatef(90,0,0,1);
    glutSolidTorus(1,5,15,20);
    glPopMatrix();

    //rodadireita
    glPushMatrix();
    glTranslatef(0,-6,7.5);
    glColor3f(0,0,0);
    glRotatef(90,0,0,1);
    glutSolidTorus(1,5,15,20);
    glPopMatrix();

    glPopMatrix();



    glPopMatrix();
    glutSwapBuffers();
}

void change_cam_view() {
    switch(cam_view){
        case 0:
            gluLookAt(100, 0, 0, 0, 0 ,0, 0, 1, 0);
            break;
        case 1: gluLookAt(0, 250, 0 ,0 ,0 ,0 , 1, 0, 0);
            break;
        
        case 2:
            gluLookAt(100, 100, 100, 0, 0, 0, 0, 1, 0);
            break;
    }
}

void configView() {
    glClearColor(0.5, 0.8, 1.0, 1.0);
    glViewport(0, 0, 800, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 800/600.0, 0.5, 500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    change_cam_view();
    glEnable(GL_DEPTH_TEST);
}

void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 27: exit(0); break;
        case 32:
            cam_view = (++cam_view % 3);
            configView();
            break;
    }
    glutPostRedisplay();
}

void specialkeys(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_UP: pos_trem += 2; break;
        case GLUT_KEY_DOWN: pos_trem -= 2; break;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Trem");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialkeys);
    configView();
    glutMainLoop();
    return 0;
}