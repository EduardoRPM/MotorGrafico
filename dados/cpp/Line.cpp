//
//  Line.cpp
//  05_lector_abstracto
//
//  Created by Eduardo Perez Martinez on 29/02/24.
//

#include "Line.hpp"
#include "Vertex.hpp"
#include <cmath> 

Line::Line(Vertex P1, Vertex P2, float dt)
{
       for ( float t=0.0; t<=1+dt; t+=dt ){
          Vertex P = P1 + ( (P2-P1)*t);
           //cout << t << endl;
           points.push_back(P);
       }
}

vector<Vertex> Line :: get_points(){
    return (this->points);
}

void Line::print_points() {
    for(Vertex p: points){
        p.print();
    }
}

void Line::print_point_at_t(float t){
    Vertex P = points[0] + ((points[points.size()-1] - points[0]) * t);
    cout << t << endl;
    P.print();
}

void Line::print_line_magnitude(){
    Vertex P1 = points[0];
    Vertex P2 = points[1];
    float dx = P2.getX() - P1.getX();
    float dy = P2.getY() - P1.getY();
    float dz = P2.getZ() - P1.getZ();
    float magnitude = sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2));
    std::cout << "La magnitud de la línea es: " << magnitude << std::endl;
}
