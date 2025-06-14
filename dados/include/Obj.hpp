//
//  Obj.hpp
//  03_OBJ
//
//  Created by Eduardo Perez Martinez on 18/02/24.
//

#ifndef Obj_hpp
#define Obj_hpp

#pragma once

#include "Model.hpp"



using namespace std;

class Obj : public Model
{
public:
    Obj() {}; //MM
    Obj(string fname);
    void set_name(string fname);
    
private:
    void load(string fname);
};



#endif /* Obj_hpp */

