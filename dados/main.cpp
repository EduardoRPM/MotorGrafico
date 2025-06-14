#include <iostream>
#include <armadillo>
#include "Vertex.hpp"
#include "Transform.hpp"
#include "Cannon.hpp"
#include "Dice.hpp"
#include "Label.hpp"
#include "include/OpenGL.h"
#include "include/Triangle.h"
#include "Object.hpp"

using namespace std;

int main() {
    OpenGL gl = OpenGL();

    GLFWwindow* window = gl.createWindow(1024, 768, "Cannon");
    if (window == NULL)
        return -1;

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glClearColor(0.1f, 0.1f, 0.1f, 0.1f);

    Dice dice1(-0.9, 0.1, 0, 89, "/models/dado1.Ply");
    Dice dice2(-0.9, 0.3, 0, 74, "/models/dado2.Ply");
    Label label1(0, -0.8, 0);


    bool shot1 = false;
    bool shot2 = false;
    

    do {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            label1.draw();
            dice1.draw();
            dice2.draw();
            glfwSwapBuffers(window);
            glfwPollEvents();
        
            int state_1 = glfwGetKey(window, GLFW_KEY_1);
            if (state_1 == GLFW_PRESS) {
                dice1.shot();
                shot1 = true;
            }
            int state_2 = glfwGetKey(window, GLFW_KEY_2);
            if (state_2 == GLFW_PRESS) {
                dice2.shot();
                shot2 = true;
            }
           

        } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
                 glfwWindowShouldClose(window) == 0);

    return 0;
}
