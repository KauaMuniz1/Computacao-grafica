#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

GLdouble rot_eng = 0;
int cam_view = 0;

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //engrenagem central
    glPushMatrix();
    glTranslatef(0,0,0);
    glColor3f(0.5,0.5,0.5);
    glutSolidTorus(1,8,15,20);
    glPopMatrix();

    //engrenagem direita
    glPushMatrix();
    glTranslatef(20, 0, 0);
    glRotatef(rot_eng,0,1,0);
    glColor3f(0,0,1);
    glutSolidTorus(1,8,15,20);
    glPopMatrix();

    //engrenagem esquerda
    glPushMatrix();
    glTranslatef(-20, 0, 0);
    glRotatef(-rot_eng,0,1,0);
    glColor3f(1,0,0);
    glutSolidTorus(1,8,15,20);
    glPopMatrix();


    glutSwapBuffers();
}

void change_cam_view() {
    switch(cam_view){
        case 0:
            gluLookAt(100, 0, 0, 0, 0, 0, 0, 1, 0);
            break;
        case 1:
            gluLookAt(0, 250, 0, 0, 0, 0, 0, 0, 1);
            break;
        case 2:
            gluLookAt(100, 100, 100, 0, 0, 0, 1, 0, 0);
            break;
    }
}

void configView() {
    glClearColor(0.1, 0.1, 0.1, 1.0);
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
        case 'a': rot_eng += 5; break;
        case 'd': rot_eng -= 5; break;
        case 32:
            cam_view = (++cam_view % 3);
            configView();
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Engrenagens");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    configView();
    glutMainLoop();
    return 0;
}