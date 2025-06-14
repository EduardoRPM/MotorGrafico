//
//  Label.hpp
//  11.Cannon.v2
//
//  Created by Eduardo Perez Martinez on 23/05/24.
//

#ifndef Label_hpp
#define Label_hpp

#pragma once
#include <stdio.h>
#include "Vertex.hpp"
#include "Object.hpp"
#include "Triangle.h"

class Label {
public:
    Label(float pos_x, float pos_y, float pos_z);
    void draw();
private:
    Object<Obj> label;
    Vertex position;
    float inclination;
};


#endif /* Cannon_hpp */
