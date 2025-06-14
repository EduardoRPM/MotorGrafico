#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Ply.hpp"



Ply::Ply(string fname) {
    this->load(fname);
}

void Ply::set_name(string fname) { // MM
    this->load(fname);
}
    
void Ply::load(string fname){
    this->name = fname;
    size_t lastSlashPos = fname.find_last_of("/\\"); // Busca el último separador de ruta en UNIX y Windows
    if (lastSlashPos != string::npos) {
        this->name = fname.substr(lastSlashPos + 1); // Extrae el nombre después del último separador
    }else {
        this->name = fname;
    }
    this->vertices = {};
    string line;
    ifstream PLYfile(fname);
    
    if (!PLYfile.is_open()) {
        cout << "No se abrio el archivo" << endl;
        return;
    }

    bool endHeader = false;
    do {
        if (!getline(PLYfile, line)) {
            break;
        }
        stringstream ss(line);
        string type;
        ss >> type;
        if (type == "end_header") {
            endHeader = true;
        }
    } while (!endHeader);


    while (getline(PLYfile, line)) {
        //cout << "Primera línea de datos: " << line << endl;
        vector<string> elemns = split(line, " ");
        if (!elemns.empty()){

            if (elemns.size()==3) { // Vértices asuminedo que no hay w
                float x = stof(elemns[0]);
                float y = stof(elemns[1]);
                float z = stof(elemns[2]);
                Vertex v(x, y, z);
                this->vertices.push_back(v);
            } else if (elemns.size()>3) { // Caras
                vector<int> indices;
                for (size_t i = 1; i < elemns.size(); i++) {
                    int index = stoi(elemns[i]);
                    indices.push_back(index);
                }
                Face f(indices);
                this->faces.push_back(f);
            }
        }
    }
}
    
    
    
    
    
    
    
    
    
    
    

    
    
    
