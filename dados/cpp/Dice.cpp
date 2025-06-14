#include "algorithm"
#include "Dice.hpp"
#include "Curve.hpp"
#include "Transform.hpp"
#include <cmath>
#include <iostream>
#include <random>


Dice::Dice(float pos_x, float pos_y, float pos_z, float initial_inclination, string fname) {
    Transform Tr;

    this->ammo.set_name(fname); //MM*/
    this->ammo.set_colors(1.0f, 0.0f, 1.0f);
    this->ammo.set_transform(Tr.T(pos_x, pos_y + 0.15, pos_z - 0.1) * Tr.S(0.08, 0.08, 0.08));

    this->position.setX(pos_x);
    this->position.setY(pos_y);
    this->position.setZ(pos_z);
    this->inclination = initial_inclination;
    this->shot_force = 0.9;
    this->shot_rotation = std::min(45.0f, initial_inclination);
    this->shot_curve = {};
    this->shooted = false;
    this->curve_index = 0;
    this->rotation_angle = 45.0f;  // Inicializa el ángulo de rotación
    this->rotation_speed = 6.0f;//6.0f;  // Inicializa la velocidad de rotación
    this->time = 0.0f;  // Tiempo inicial para la función seno
    
    
    // Inicializar num_rand1, num_rand2 y num_rand3
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(10, 45);
    this->num_rand1 = dis(gen);
    this->num_rand2 = dis(gen);
    this->num_rand3 = dis(gen);

}

void Dice::shot() {
    // Inicializar num_rand1, num_rand2 y num_rand3 con -1 o 1
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 1);
        this->num_rand1 = dis(gen) == 0 ? -1 : 1;
        this->num_rand2 = dis(gen) == 0 ? -1 : 1;
        this->num_rand3 = dis(gen) == 0 ? -1 : 1;
    this->shooted = true;
    Vertex pos_ammo(this->position.getX(), this->position.getY() + 0.15, this->position.getZ() - 0.1);

    std::vector<Vertex> control_points;
    control_points.push_back(pos_ammo);

    float current_force = this->shot_force;
    float energy_loss = 0.5;  // Define el porcentaje de energía que se pierde en cada rebote
    float ground_level = -0.5; // Nivel del suelo
    float inclination_radians = this->inclination * (M_PI / 180.0); // Convierte la inclinación a radianes

    while (current_force > 0.1) {  // Continua hasta que la fuerza es 0
        Vertex last_point = control_points.back();

        // Calcula las componentes de la inclinación inicial
        float dx = current_force * cos(inclination_radians);
        float dy = current_force * sin(inclination_radians);

        // Define los puntos de control para el rebote
        Vertex P1(last_point.getX() + dx, last_point.getY() + dy * 0.5, last_point.getZ());
        Vertex P2(P1.getX() + dx, P1.getY(), P1.getZ());
        Vertex P3(P2.getX() + dx, ground_level, P2.getZ());

        // Genera la curva de Bézier para este segmento
        Curve segment_curve(last_point, P1, P2, P3, 0.05);
        std::vector<Vertex> segment_points = segment_curve.get_points();
        this->shot_curve.insert(shot_curve.end(), segment_points.begin(), segment_points.end());

        // Añade el último punto como el nuevo punto de control
        control_points.push_back(P3);

        // Reduce la fuerza debido a la pérdida de energía
        current_force *= energy_loss;
    }
    
    // Actualiza shot_force para que draw() pueda usarla
    this->shot_force = current_force;
}


void Dice::draw() {
    Transform tr;

    if (this->shooted) {
        if (this->curve_index < this->shot_curve.size()) {
            Vertex p = this->shot_curve[curve_index];
            // Incrementar el índice después de acceder al punto de la curva
            this->curve_index++;

            // Incrementar el tiempo para la función seno
            this->time += 0.1f;

            // Calcular la velocidad de rotación usando una función seno y la fuerza actual
            float force_factor = std::max(0.1f, this->shot_force*this->shot_rotation);  // Asegúrate de que no sea menor a un valor pequeño
            this->rotation_speed = 50.0f * std::abs(std::sin(this->time)) * force_factor;

            // Incrementar el ángulo de rotación según la velocidad de rotación
            this->rotation_angle += this->rotation_speed;

            // Mover la bala a la posición p
            arma::Mat<float> T2ammo = tr.T(p.getX(), p.getY(), p.getZ());

            // Rotación
            arma::Mat<float> R = tr.Rx(this->rotation_angle * num_rand1) * tr.Ry(this->rotation_angle * num_rand2) * tr.Rz(this->rotation_angle * num_rand3 );
            this->ammo.set_transform(T2ammo * R * tr.S(0.08, 0.08, 0.08));
        } else {
            // Detener la bala en la última posición de la curva y mantener la rotación
            Vertex p = this->shot_curve.back();
            arma::Mat<float> T2ammo = tr.T(p.getX(), p.getY(), p.getZ());

            // Rotación
            arma::Mat<float> R = tr.Rx(this->rotation_angle * num_rand1) * tr.Ry(this->rotation_angle * num_rand2) * tr.Rz(this->rotation_angle * num_rand3);
            this->ammo.set_transform(T2ammo * R * tr.S(0.08, 0.08, 0.08));
        }
    }

    Triangle am(this->ammo.get_vertex_buffer_data(), this->ammo.get_vertex_color_data());
    am.draw();
}
