//
//  Curve.hpp
//  Curva
//
//  Created by Eduardo Perez Martinez on 20/03/24.
//

#ifndef Curve_hpp
#define Curve_hpp


#pragma once
#include "Vertex.hpp"
#include <stdio.h>
#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;


class Curve {
public:
    Curve(Vertex P1, Vertex P2, Vertex P3, Vertex P4, float dt);
    vector<Vertex> get_points();
private:
    Vertex vi, vf;
    vector<Vertex> points;
};

#endif /* Curve_hpp */

