//
//  Face.cpp
//  Cube
//
//  Created by Eduardo Perez Martinez on 17/02/24.
//

#include "Face.hpp"
#include <cmath>
//#include "../include/Face.h"



Face::Face(vector<int> indices)
{
    this->indices=indices;
}

double Face::calculatePerimeter(vector<Vertex>& vertices){
    double perimeter = 0.0;
    for (size_t i = 0; i < indices.size(); ++i) {
        // Obtener los vértices adyacentes para calcular la longitud
        Vertex v1 = vertices[indices[i]];
        Vertex v2 = vertices[indices[(i + 1) % indices.size()]]; // El índice del vértice siguiente
        // Calcular la distancia entre los vértices adyacentes y agregarla al perímetro total
        perimeter += sqrt(pow(v2.getX() - v1.getX(), 2) + pow(v2.getY() - v1.getY(), 2) + pow(v2.getZ() - v1.getZ(), 2));
    }
    return perimeter;
}

vector<int>::size_type Face::getNumSides()  {
    return this->indices.size();
}

vector<int> Face::get_indices(){
    return (this->indices);
}

void Face::calculateNormal(vector<Vertex>& vertices) {
    if (indices.size() < 3) return; // Necesitamos al menos 3 vértices para definir una cara

    Vertex v1 = vertices[indices[0]];
    Vertex v2 = vertices[indices[1]];
    Vertex v3 = vertices[indices[2]];

    // Vector u = v2 - v1
    float ux = v2.getX() - v1.getX();
    float uy = v2.getY() - v1.getY();
    float uz = v2.getZ() - v1.getZ();

    // Vector v = v3 - v1
    float vx = v3.getX() - v1.getX();
    float vy = v3.getY() - v1.getY();
    float vz = v3.getZ() - v1.getZ();

    // Producto cruzado u x v
    float nx = uy * vz - uz * vy;
    float ny = uz * vx - ux * vz;
    float nz = ux * vy - uy * vx;

    // Normalizamos el vector normal
    float length = sqrt(nx * nx + ny * ny + nz * nz);
    if (length > 0.0f) {
        nx /= length;
        ny /= length;
        nz /= length;
    }

    normal = {nx, ny, nz};
}

vector<float> Face::getNormal() {
    return normal;
}
