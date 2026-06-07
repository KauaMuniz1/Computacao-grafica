#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

GLdouble rot_helice = 0;
int cam_view = 0;

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glColor3f(1,1,1);
    glScalef(60,20,20);
    glutSolidCube(1);
    glPopMatrix();

    //asa esquerda
    glPushMatrix();
    glTranslatef(0,0,-20);
    glColor3f(0,1,0);
    glScalef(20,2,20);
    glutSolidCube(1);

    glPopMatrix();


    //asa direita
    glPushMatrix();
    glTranslatef(0,0,20);
    glColor3f(0,1,0);
    glScalef(20,2,20);
    glutSolidCube(1);

    glPopMatrix();

    //helice
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(38,0,0);
    glRotatef(rot_helice,1,0,0);

    //pá 1
    glPushMatrix();
    glColor3f(0,0,1);

    glScalef(2,20,3);
    glutSolidCube(1);
    glPopMatrix();

    //pa 2
    glPushMatrix();
    glColor3f(0,0,1);

    glRotatef(120,0,0,1);
    glScalef(2,20,3);
    glutSolidCube(1);

    glPopMatrix();

    //pá 3
    glPushMatrix();
    glColor3f(0,0,1);
    glRotatef(240,0,0,1);
    glScalef(2,20,3);
    glutSolidCube(1);

    glPopMatrix();


    glPopMatrix();


    glutSwapBuffers();
}

void change_cam_view() {
    switch(cam_view) {
        case 0: gluLookAt(100, 0, 0, 0, 0, 0, 0, 1, 0); 
            break;
        
        case 1: 
            gluLookAt(0, 200, 0, 0, 0, 0, 1, 0, 0);
            break;

        case 2: 
            gluLookAt(100,100, 100, 0, 0, 0, 0, 1, 0); 
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
        case 'a': rot_helice += 5; break;
        case 'd': rot_helice -= 5; break;
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
    glutCreateWindow("Helice");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    configView();
    glutMainLoop();
    return 0;
}