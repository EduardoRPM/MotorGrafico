//
//  Transform.hpp
//  09.transforms
//
//  Created by Eduardo Perez Martinez on 07/04/24.
//

#ifndef Transform_hpp
#define Transform_hpp

#include <stdio.h>
#pragma once
#include <armadillo>
#include "Vertex.hpp"
class Transform
{
public:
    Transform();
    arma::Mat<float> T(float dx, float dy, float dz);
    arma::Mat<float> S(float sx, float sy, float sz);
    arma::Mat<float>Rx(float theta);
    arma::Mat<float>Ry(float theta);
    arma::Mat<float>Rz(float theta);
private:
};

#endif /* Transform_hpp */
