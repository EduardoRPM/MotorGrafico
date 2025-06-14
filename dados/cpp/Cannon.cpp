//
//  Cannon.cpp
//  09.transforms
//
//  Created by Eduardo Perez Martinez on 16/04/24.
//
#include "algorithm"
#include "Cannon.hpp"
#include "Curve.hpp"
#include "Transform.hpp"

Cannon::Cannon(float pos_x, float pos_y, float pos_z)
{
    Transform Tr;
    
    this->body.set_name("/Users/eduardoperez/Documents/Graficacion_Por_Computadora_Cpp/11.Cannon.v2/11.Cannon.v2/models/dado1.obj"); //MM
    this->body.set_colors(1.0f, 0.0f, 0.0f);
    this->angle = 45.0;
    this->body.set_transform(Tr.T(pos_x, pos_y, pos_z)* Tr.Rz(this->angle) * Tr.S(0.3,0.15,0.15));
    
    
    this->wheel.set_name("/Users/eduardoperez/Documents/Graficacion_Por_Computadora_Cpp/11.Cannon.v2/11.Cannon.v2/models/dado2.Ply");//MM
    this->wheel.set_colors(0.0f, 1.0f, 0.0f);
    this->wheel.set_transform(Tr.T(pos_x, pos_y-0.1, pos_z) * Tr.S(0.1,0.1,0.1));
    
    this->ammo.set_name("/Users/eduardoperez/Documents/Graficacion_Por_Computadora_Cpp/11.Cannon.v2/11.Cannon.v2/models/dado3.Ply"); //MM*/
    this->ammo.set_colors(1.0f, 0.0f, 1.0f);
    this->ammo.set_transform(Tr.T(pos_x, pos_y+0.15, pos_z-0.1) * Tr.S(0.08,0.08,0.08));
    
    
    this->position.setX(pos_x);
    this->position.setY(pos_y);
    this->position.setZ(pos_z);
    this->inclination = 45;
    this->shot_force = 0.5;
    this->shot_curve = {};
    this->shooted = false;
    this->curve_index = 0;
}

void Cannon::shot(){
    
    this->shooted = true;
    //    this->ammo.set_transform(Tr.T(pos_x, pos_y+0.15, pos_z-0.1) * Tr.S(0.08,0.08,0.08));
    Vertex pos_ammo(this->position.getX(),
                   this->position.getY()+0.15,
                   this->position.getZ()-0.1);
    // Paso 1Coloar a la bala en su posicion inicial
    Transform tr;
    arma::Mat<float> T1ammo = tr.T(pos_ammo.getX(), pos_ammo.getY(), pos_ammo.getZ());
    
    Vertex P1 = pos_ammo;
    Vertex P2(pos_ammo.getX()+(this->shot_force),
              pos_ammo.getY()+0.7,
              pos_ammo.getZ());
    Vertex P3(P2.getX()+(this->shot_force), P2.getY(), P2.getZ());
    Vertex P4(P2.getX()+(this->shot_force*2), 0, P2.getZ());
    
    Curve sc(P1, P2, P3, P4, 0.01);
    this->shot_curve = sc.get_points();
    
    
}

void Cannon::draw()
{
    Transform tr;
    
    Triangle bd(this->body.get_vertex_buffer_data(), this->body.get_vertex_color_data());
    bd.draw();
    Triangle wh(this->wheel.get_vertex_buffer_data(), this->wheel.get_vertex_color_data());
    wh.draw();
    if(this->shooted)
    {
        Vertex p = this->shot_curve[curve_index];
        if(this->curve_index< this->shot_curve.size())
            this->curve_index++;
        //PASO2. mover la bala a la pos p
        arma::Mat <float> T2ammo= tr.T(p.getX(), p.getY(),p.getZ());
        this->ammo.set_transform(T2ammo * tr.S(0.08,0.08,0.08));
        
    }
    Triangle am(this->ammo.get_vertex_buffer_data(), this->ammo.get_vertex_color_data());
    am.draw();
    
}

void Cannon::set_angle(float angle){
    Transform Tr;
    
    this->angle += angle;
    if(this->angle < 0)
        this->angle = 0;
    else if (this->angle > 90)
        this->angle = 90;

    this->body.set_transform(Tr.T(this->position.getX(), this->position.getY(), this->position.getZ())* Tr.Rz(this->angle) * Tr.S(0.3,0.15,0.15));

}
