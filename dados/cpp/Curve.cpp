//
//  Curve.cpp
//  Curva
//
//  Created by Eduardo Perez Martinez on 20/03/24.
//

#include "Curve.hpp"



Curve::Curve(Vertex P1, Vertex P2, Vertex P3, Vertex P4, float dt)
{
    this->vi = P1;
    this->vf = P4;
    points = {};
    
    arma::Mat<float> MB = { {-1, 3, -3, 1},
                        {3, -6, 3, 0},
                        {-3, 3, 0, 0},
                        {1, 0, 0, 0} };

    arma::Mat<float> GB = { {P1.getX(),P1.getY(),P1.getZ()},
                            {P2.getX(),P2.getY(),P2.getZ()},
                            {P3.getX(),P3.getY(),P3.getZ()},
                            {P4.getX(),P4.getY(),P4.getZ()}  };

    for (float t=0.0; t <= 1.0+dt; t+=dt)
    {
        arma::Row<float> T = { powf(t, 3), powf(t, 2), t, 1 };
        arma::Mat<float> Qt = T * MB * GB;
        
        Vertex P(Qt[0], Qt[1], Qt[2]);
        points.push_back(P);
        //cout << "t = " << t << endl << Qt << endl; imprimir los puntos
    }

}


vector<Vertex> Curve::get_points(){
    return (this->points);
}
