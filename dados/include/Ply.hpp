//
//  Ply.hpp
//  04_PLY
//
//  Created by Eduardo Perez Martinez on 18/02/24.
//

#ifndef Ply_hpp
#define Ply_hpp

#pragma once

#include "Model.hpp"


using namespace std;

class Ply : public Model
{
public:
    Ply() {}; //MM
    Ply(string fname);
    void set_name(string fname);
private:
    void load(string fname);
};



#endif /* Ply_hpp */




