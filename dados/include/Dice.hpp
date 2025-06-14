#ifndef Dice_hpp
#define Dice_hpp

#pragma once
#include <vector>
#include "Vertex.hpp"
#include "Object.hpp"
#include "Triangle.h"

class Dice {
public:
    Dice(float pos_x, float pos_y, float pos_z, float initial_inclination, string fname);
    void shot();
    void draw();
    void show();
    
private:
    
    Object<Ply> ammo;
    Vertex position;
    float inclination;
    float shot_force;
    float shot_rotation;
    float angle;
    vector<Vertex> shot_curve;
    bool shooted;
    int curve_index;
    float rotation_angle;
    float rotation_speed;
    float current_force;
    float trajectory_speed;
    float time;
    int num_rand1;
    int num_rand2;
    int num_rand3;
};


#endif /* Dice_hpp */
