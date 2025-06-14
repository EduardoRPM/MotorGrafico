//
//  Label.cpp
//  11.Cannon.v2
//
//  Created by Eduardo Perez Martinez on 23/05/24.
//

#include "Label.hpp"



#include "Curve.hpp"
#include "Transform.hpp"

Label::Label(float pos_x, float pos_y, float pos_z)
{
    Transform Tr;
    
    
    
    this->label.set_name("/models/letrero.Obj"); //MM*/
    this->label.set_colors(1.0f, 0.0f, 1.0f);
    this->label.set_transform(Tr.T(pos_x, pos_y, pos_z) * Tr.Rx(90));
    
    
    this->position.setX(pos_x);
    this->position.setY(pos_y);
    this->position.setZ(pos_z);
    
    this->inclination = 45;
}


void Label::draw()
{
    Transform tr;
    Triangle lb(this->label.get_vertex_buffer_data(), this->label.get_vertex_color_data());
    lb.draw();
    
}

