//
//  Model.cpp
//  05_lector_abstracto
//
//  Created by Eduardo Perez Martinez on 26/02/24.
//

#include "Model.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include "Vertex.hpp"
#include "Face.hpp"
#include <cmath>


Model::Model()
{
    this->transform = { {1.0, 0.0, 0.0, 0.0},
                        {0.0, 1.0, 0.0, 0.0},
                        {0.0, 0.0, 1.0, 0.0},
                        {0.0, 0.0, 0.0, 1.0} };
}

vector<string> Model::split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}


void Model::info(){
   //nombre del objeto 1) o/g o el nombre del archivo sin extensión
    cout << "Nombre del objeto: " << this->name << endl;
    //numero de vertices
    cout << "Número de vértices: " << this->vertices.size() << endl;
    //nuemro de caras
    cout << "Número de caras: " << this->faces.size() << endl;
}

vector<Vertex> Model::get_vertices(){
    return(this->vertices);
}


vector<Face> Model::get_faces(){
    return(this->faces);
}

vector<GLfloat> Model::get_vertex_buffer_data()
{
    vector<GLfloat> vertex_buffer_data={};
    for (Face f:this->get_faces())
    {
          for (int vi: f.get_indices())
          {
              Vertex v=this->get_vertices()[vi];
              arma::Mat<float> vp = this->transform * v.h();
              vertex_buffer_data.push_back(vp.at(0.0) /vp.at(3.0));
              vertex_buffer_data.push_back(vp.at(1.0) /vp.at(3.0));
              vertex_buffer_data.push_back(vp.at(2.0) /vp.at(3.0));
          }
          
    }
    
    return(vertex_buffer_data);
}

vector<GLfloat> Model::get_vertex_color_data()
{
    int sum= 0;
    vector<GLfloat> vertex_color_data={};
    for (Face f:this->get_faces())
    {
          for (int vi: f.get_indices())
          {
              vertex_color_data.push_back(fmod(this->r + sum*7, 255.0f) / 255.0f);  // Normaliza a [0,1] para colores RGB
                          vertex_color_data.push_back(fmod(this->g + sum, 255.0f) / 255.0f);  // Normaliza a [0,1] para colores RGB
                          vertex_color_data.push_back(fmod(this->b + sum*11, 255.0f) / 255.0f);  // Normaliza a [0,1] para colores RGB
          }
        sum+=3;
    }
    
    return(vertex_color_data);
}


void Model::set_colors(float r, float g, float b){
    this->r = r;
    this->g = g;
    this->b = b;
}


void Model::set_transform(arma::Mat<float> trnsf)
{
    this->transform = trnsf;
}
