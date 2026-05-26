#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

void display(); 

void init(){
    //define a cor de limpeza da tela, parametros: (vermelho, verde, azul, alpha)
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char**argv){
    glutInit(&argc, argv);


    /*define o modo de exibição
    GLUT_RGB: cores no formato rgb
    GLUT_DOUBLE: usa dois buffers
    */
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);


    //Define a posição inicial da janela na tela usando escala x y (x = 200, y = 100, em pixels)
    glutInitWindowPosition(200, 100);


    //define o tamanho da janela (500x500 em pixels)
    glutInitWindowSize(500,500);


    //cria a janela com o titulo "windows 1"
    glutCreateWindow("Window 1");


    //registra a função display como callback de renderização (o GLUT vai chamar display sempre que precisar redesenhar a janela)
    glutDisplayFunc(display);
    init();


    //inicia o loop principal do GLUT(fica rodando até o programa fechar)
    glutMainLoop();
}

void display(){

    //Limpa o buffer de cor, pintando a tela com a cor já definida no glClearColor
    glClear(GL_COLOR_BUFFER_BIT);

    //Reseta a matriz de transformação atual para a identidade
    glLoadIdentity();

    //draw


    //Troca o buffer de trás com o de frente
    glutSwapBuffers(); 
}
