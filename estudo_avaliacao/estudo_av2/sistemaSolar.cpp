#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

GLdouble ano = 0, mes = 0;
int cam_view = 0;

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glColor3f(1,1,0);
    glutSolidSphere(5,20,16);

    glPushMatrix();
        glRotatef(ano, 0, 1, 0);
        glTranslatef(30, 0, 0);
        glColor3f(0,1,1);
        glutSolidSphere(2, 10, 16);

        glPushMatrix();
            glRotatef(mes, 0, 1, 0);
            glTranslatef(10,0,0);
            glColor3f(0.5,0.5,0.5);
            glutSolidSphere(1,3,16);
        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

void change_cam_view() {
    switch(cam_view){
        case 0:
            gluLookAt(100, 0, 0, 0, 0, 0, 0, 1, 0);
            break;

        case 1:
            gluLookAt(0, 250, 0, 0, 0, 0, 1, 0, 0);
            break;

        case 2:
            gluLookAt(0, 0, 100, 0, 0, 0, 0, 0, 1);
            break;

    }

}

void configView() {
    glClearColor(1,1,1,1);
    glViewport(0,0,800,600);
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
        case 'a': ano += 5; break;
        case 'd': ano -= 5; break;
        case 'w': mes += 10; break;
        case 's': mes -= 10; break;
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
    glutInitWindowSize(800,600);
    glutCreateWindow("Sistema Solar");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    configView();
    glutMainLoop();
    return 0;
}