//
//  Line.hpp
//  05_lector_abstracto
//
//  Created by Eduardo Perez Martinez on 29/02/24.
//

#ifndef Line_hpp
#define Line_hpp

#pragma once

#include <stdio.h>
#include "Vertex.hpp"
#include <vector>

using namespace std;

class Line{
public:
    Line(Vertex P1, Vertex P2, float dt);
    vector<Vertex> get_points();
    void print_points();
    void print_point_at_t(float t);
    void print_line_magnitude();
private:
    vector<Vertex> points;
    
};

#endif /* Line_hpp */
