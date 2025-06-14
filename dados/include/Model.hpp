//
//  Model.hpp
//  05_lector_abstracto
//
//  Created by Eduardo Perez Martinez on 26/02/24.
//

#ifndef Model_hpp
#define Model_hpp

#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <armadillo>
#include "Vertex.hpp"
#include "Face.hpp"


using namespace std;

class Model
{
public:
    Model();
    void info();
    void set_colors(float r, float g, float b);
    vector<Vertex> get_vertices();
    vector<Face> get_faces();
    vector <GLfloat> get_vertex_buffer_data();
    vector <GLfloat> get_vertex_color_data();
    void set_transform(arma::Mat<float> trnsf);
protected:
    void load(string fname);
    string name;
    float r, g, b;
    arma::Mat<float> transform;
    vector<Vertex> vertices;
    vector<Face> faces;
    vector<string> split(const string& str, const string& delim);
};

#endif /* Model_hpp */
