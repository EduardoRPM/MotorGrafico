//
//  Obj.cpp
//  03_OBJ
//
//  Created by Eduardo Perez Martinez on 18/02/24.
//
#include <iostream>
#include <vector>
#include <fstream>
#include "Obj.hpp"
#include "Ply.hpp"
#include "Vertex.hpp"
#include "Face.hpp"



Obj::Obj(string fname){
    this->load(fname);
}

void Obj::set_name(string fname){ //MM
    this->load(fname);
}

void Obj::load(string fname)
{
    this->name = "";
    this->vertices = {};
    this->faces = {};
    string line;
    
    ifstream OBJfile(fname);

    while (getline(OBJfile, line))
    {
        
        vector<string> elemns = this->split(line, " ");
        if (!elemns.empty()) {
            if (elemns[0] == "o") {
                if (elemns.size()>1)
                    this->name = elemns[1];
            }
            if(elemns[0] == "g" && this->name.size() == 0){
                if (elemns.size()>1)
                    this->name = elemns[1];
            }
            if  (elemns [0] == "v")
            {
                float x = stof(elemns[1]);
                float y = stof(elemns[2]);
                float z = stof(elemns[3]);
                
                Vertex v(x, y, z);
                this->vertices.push_back(v);
                
            }
            if(elemns[0] == "f")
            {
                vector<int> ind = {};
                for (int i=1; i<elemns.size();i++)
                {
                    int v = stoi(this->split(elemns[i], "/")[0])-1;
                    ind.push_back(v);
                }
                Face f(ind);
                this->faces.push_back(f);
            }
        }
    }
}


