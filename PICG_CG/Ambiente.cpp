#include "Ambiente.h"
#include <GL/gl.h>
#include <iostream>
#include <vector>
#include <cmath>


Ambiente::Ambiente(float sizeIlha):sizeIlha(sizeIlha)
{
    //carregar a textura do chão.


}
void Ambiente::criarIlha(vector<vector<char>> &mundo){
    //considerando que a matriz 100x80 tera 80 por cento da ilha

    float porOceano = 100 - this->sizeIlha;

    int initX = porOceano/4;
    int intiZ = porOceano/4;
    int endX = (int) (mundo[0].size() - (porOceano/4));
    int endZ = int (mundo.size() - (porOceano/4));
    //relacao de aspecto
    for(int i = intiZ+1;i<endZ;i++){
        for(int j = initX+1;j<endX;j++){
            //identificador ilha
            mundo[i][j] = 'i';
        }
    }
}

//chamar esse metodo antes de criar ilha
void Ambiente::criarOceano(vector<vector<char>>&mundo){
    for(int i = 0; i<mundo.size();i++){
        for(int j=0;j<mundo[i].size();j++){
            mundo[i][j] = 'o';
        }
    }
}
//desenhar  ambiente no opengl
void Ambiente::desenharAmbiente(vector<vector<char>>mundo){
    int R, G, B;
    for(int i=0;i<mundo.size()-1;i++){
        for(int j=0;j<mundo[i].size()-1;j++){
            if(mundo[i][j] == 'o'){
                    R = 58;
                    G = 144;
                    B = 255;
            }
            else if (mundo[i][j] == 'i'){
                R = 0;
                G = 128;
                B = 0;
            }
            else{R = 0; G = 0; B =0;}
            glColor3ub(R, G, B);
            glPushMatrix();

            glBegin(GL_QUADS);
            glVertex3f(i, 0.5f, j);
            glVertex3f(i, 0.5f, j + 1);
            glVertex3f(i + 1, 0.5f, j + 1);
            glVertex3f(i + 1, 0.5f, j);
            glEnd();
            glPopAttrib();
            glPopMatrix();



        }
    }



}






int Ambiente::getAreaI(vector<vector<char>> mundo){
    return (int) ((mundo[0].size()*mundo.size()*this->sizeIlha))/100;
}


Ambiente::~Ambiente()
{
    //dtor
}



Ambiente::Ambiente(const Ambiente& other)
{
    //copy ctor
}

Ambiente& Ambiente::operator=(const Ambiente& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
