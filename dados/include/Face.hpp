//
//  Face.hpp
//  Cube
//
//  Created by Eduardo Perez Martinez on 17/02/24.
//

#ifndef Face_hpp
#define Face_hpp

#pragma once
#include <iostream>
#include <vector>
#include "Vertex.hpp"

using namespace std;

class Face
{
private:
   vector<int> indices;
   vector<float> normal;
public:
    Face(vector<int> indices);
    void print();
    double calculatePerimeter(vector<Vertex>& vertices); //Perimetro
    vector<int>::size_type getNumSides(); //Número de lados
    vector<int> get_indices();
    void calculateNormal(vector<Vertex>& vertices); // Nueva función para calcular la normal
    vector<float> getNormal(); // Nueva función para obtener la normal
};

#endif /* Face_hpp */
