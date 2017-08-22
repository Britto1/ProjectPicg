
#include <vector>
#include <string>
#include <cstdlib>
#include <GL/freeglut.h>
#include "Ambiente.h"
#include <GL/glu.h>
#include <iostream>
static GLfloat spin = 0.0;
using namespace std;

Ambiente *ambiente;
vector<vector<char>> mundo;
void init(){
    int codX = 80;
    int codZ = 100;
    float sizeIlha = 80;

    mundo.resize((int )codZ);
    for(int i=0;i<mundo.size();i++){
        mundo[i].resize((int)codX);
    }
    glClearColor(0,0,0.0,0.0);
    glPolygonMode(GL_BACK, GL_LINE);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
     gluPerspective(90, (GLfloat) codX / (GLfloat) codZ, 0.1f, 1000);
    ambiente = new  Ambiente(sizeIlha);
    ambiente->criarOceano(mundo);
    ambiente->criarIlha(mundo);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            40,
            100*0.8,
            100*0.3,
            40,
           100*0.8-0.2,
            100*0.3+0.1,
            0.0,
            1.0,
            0.0);
    glPushMatrix();

    glPushAttrib(GL_CURRENT_BIT);
   // glPushMatrix();

    ambiente->desenharAmbiente(mundo);
    glPopAttrib();
    glPopMatrix();
    glutSwapBuffers();

}

void spinDisplay(void) {
    spin = (GLfloat) (spin + 2.0);
    if (spin > 360.0)
        spin = (GLfloat) (spin - 360.0);

    glutPostRedisplay();
}

//função chamada quando a tela é redimensionada
void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
}


int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(500,500);
    glutCreateWindow("Janela");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    //cout<<"erro"<<endl;
    glutMainLoop();


    return 0;
}



