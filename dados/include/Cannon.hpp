//
//  Cannon.hpp
//  09.transforms
//
//  Created by Eduardo Perez Martinez on 16/04/24.
//

#ifndef Cannon_hpp
#define Cannon_hpp

#pragma once
#include <stdio.h>
#include "Vertex.hpp"
#include "Object.hpp"
#include "Triangle.h"

class Cannon {
public:
    Cannon(float pos_x, float pos_y, float pos_z);
    void shot();
    void draw();
    void set_angle(float angle);
private:
    Object<Obj> body;
    Object<Ply> wheel; //MM
    Object<Ply> ammo;
    Vertex position;
    float inclination;
    float shot_force;
    float angle;
    vector<Vertex> shot_curve;
    bool shooted;
    int curve_index;
};


#endif /* Cannon_hpp */
