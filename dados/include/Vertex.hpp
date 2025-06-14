//
//  Vertex.hpp
//  Cube
//
//  Created by Eduardo Perez Martinez on 17/02/24.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#include <stdio.h>


#pragma once

#include <iostream>
#include <armadillo>

using namespace std;

class Vertex
{
private:
    float x,y,z;
public:
    Vertex(){}; //constructor
    Vertex(float x, float y, float z);
    void print();
    // Getters
    float getX();
    float getY();
    float getZ();
    // Setters
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    Vertex operator+(Vertex P2);
    Vertex operator-(Vertex P2);
    Vertex operator*(float f);
    arma::Col<float> h();
};


#endif /* Vertex_hpp */
