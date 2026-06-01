#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

void display(); 
void reshape(int, int);
void timer(int);
float angle = 0.0;


void init(){
    //define a cor de limpeza da tela, parametros: (vermelho, verde, azul, alpha)
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glEnable(GL_DEPTH_TEST);
}



void display(){

    //Limpa o buffer de cor, pintando a tela com a cor já definida no glClearColor
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Reseta a matriz de transformação atual para a identidade
    glLoadIdentity();

    glTranslatef(0,0, -8);
    glRotatef(angle, 1,0,0);
    glRotatef(angle, 0, 1, 0);
    glRotatef(angle, 0, 0, 1);

    //Desenhando um cubo
    glBegin(GL_QUADS);

    //front
    glColor3f(1,0,0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0); //todos os z's vao ser iguais a 1
    
    //back
    glColor3f(0.0,1.0,0.0);
    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,1.0,-1.0); //todos os z's vao ser iguais a -1

    //right
    glColor3f(0.0,0.0,1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0); //um z vai estar a -1

    //left
    glColor3f(1.0,1.0,0.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(-1.0,1.0,1.0); //mesma ideia da de cima

    //top
    glColor3f(0.0,1.0,1.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,1.0,-1.0); //vai haver 2 z's negativos

    //bottom
    glColor3f(1.0,0.0,1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,-1.0); //aqui também há 2 z's negativos 

    //
    glEnd();
    //Troca o buffer de trás com o de frente
    glutSwapBuffers(); 
}

void reshape(int w, int h){
    //define a área de pixels da janela onde a opengl vai renderizar
    glViewport(0,0, w, h);//x,y,largura,altura

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //define uma projeção ortográfica 2D, e os parametros definem os limites do mundo
    gluPerspective(60, 1, 2.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
   
}


void timer(int){ 

    //glutPostRedisplay() avisa o glut que a janela precisa ser redesenhada, o que faz ele chamar display()na proxima iteração do loop
    glutPostRedisplay();

    //Re-registra o timer para chamar a mesma função depois de -16ms, criando um loop de animação de aproximadamente 60 fps
    glutTimerFunc(1000/60, timer, 0);

    //verifica o estado atual (1 = indo pra direita, -1 = indo pra esquerda)
    
    angle += 0.8 * 2;
    if(angle > 360.0){
        angle = angle - 360;
    }

}

int main(int argc, char**argv){
    glutInit(&argc, argv);


    /*define o modo de exibição
    GLUT_RGB: cores no formato rgb
    GLUT_DOUBLE: usa dois buffers
    */
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);


    //Define a posição inicial da janela na tela usando escala x y (x = 200, y = 100, em pixels)
    glutInitWindowPosition(200, 100);


    //define o tamanho da janela (500x500 em pixels)
    glutInitWindowSize(500,500);


    //cria a janela com o titulo "windows 1"
    glutCreateWindow("Window 1");


    //registra a função display como callback de renderização (o GLUT vai chamar display sempre que precisar redesenhar a janela)
    glutDisplayFunc(display);
    
    glutReshapeFunc(reshape);
    
    glutTimerFunc(1000, timer, 0);
    init();
    //inicia o loop principal do GLUT(fica rodando até o programa fechar)
    glutMainLoop();
}

