//
//  Vertex.cpp
//  Cube
//
//  Created by Eduardo Perez Martinez on 17/02/24.
//

#include "Vertex.hpp"
//#include "../include/Vertex.h"

Vertex::Vertex(float x, float y, float z)
{
    this->x=x;
    this->y=y;
    this->z=z;
}
void Vertex::print(){
    cout<< "(" << this->x << ", "<< this->y << ", " << this->z << ")"<< endl;
}

float Vertex::getX()  {
    return x;
}

float Vertex::getY()  {
    return y;
}

float Vertex::getZ()  {
    return z;
}

void Vertex::setX(float x) {
    this->x = x;
}

void Vertex::setY(float y) {
    this->y = y;
}

void Vertex::setZ(float z) {
    this->z = z;
}


Vertex Vertex::operator+(Vertex P2){
    float x = this->x + P2.x;
    float y = this->y + P2.y;
    float z = this->z + P2.z;
    Vertex P(x, y, z);
    return (P);
}


Vertex Vertex::operator-(Vertex P2){
    float x = this->x - P2.x;
    float y = this->y - P2.y;
    float z = this->z - P2.z;
    Vertex P(x, y, z);
    return (P);
}


Vertex Vertex::operator*(float f){
    float x = this->x * f;
    float y = this->y * f;
    float z = this->z * f;
    Vertex P(x, y, z);
    return (P);
}

arma::Col<float> Vertex::h()
{
    arma::Col<float> vh = {this->x, this->y, this->z, 1};
    return(vh);
}
