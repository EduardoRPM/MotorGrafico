//
//  Transform.cpp
//  09.transforms
//
//  Created by Eduardo Perez Martinez on 07/04/24.
//

#include "Transform.hpp"
#include "Vertex.hpp"
#include <cmath> // Para atan2f

Transform::Transform(){
    
}

arma::Mat<float> Transform::T(float dx, float dy, float dz)
{
    arma::Mat<float> T1= {  {1,0,0,dx},
                            {0,1,0,dy},
                            {0,0,1,dz},
                            {0,0,0,1}};
    return (T1);
}

arma::Mat<float> Transform::S(float sx,float sy,float sz){
    arma::Mat<float> S1= {  {sx,0,0,0},
                            {0,sy,0,0},
                            {0,0,sz,0},
                            {0,0,0,1}};
    return (S1);
}
//rotacion
arma::Mat<float> Transform::Rx(float theta){
    #define PI 3.14159
    float ang = (theta * PI)/180;
    arma::Mat<float> Rx1= {  {1,0,0,0},
                            {0,cosf(ang),-sinf(ang),0},
                            {0,sinf(ang),cosf(ang),0},
                            {0,0,0,1}};
    return (Rx1);
}

arma::Mat<float> Transform::Ry(float theta){
    #define PI 3.14159
    float ang = (theta * PI)/180;
    arma::Mat<float> Ry1= {  {cosf(ang),0,sinf(ang),0},
                            {0,1,0,0},
                            {-sinf(ang),0,cosf(ang),0},
                            {0,0,0,1}   };
    return (Ry1);
}
arma::Mat<float> Transform::Rz(float theta){
    #define PI 3.14159
    float ang = (theta * PI)/180;
    arma::Mat<float> Rz1= {  {cosf(ang),-sinf(ang),0,0},
                        {sinf(ang),cosf(ang),0,0},
                        {0,0,1,0},
                        {0,0,0,1}   };
    return (Rz1);
}
