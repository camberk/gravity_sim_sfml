#ifndef SIM_H
#define SIM_H

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Particle.h"
#include "Source.h"
#include <vector>
#include "Rng.h"

class Sim
{
private:
    sf::RenderWindow* window;
    sf::Event sfmlEvent;
    std::vector<Particle*> particles;
    Source source_shape;
    float max_screen_dim_x;
    float max_screen_dim_y;

    void initVars();
public:
    Sim();
    ~Sim();

    void run();

    void update();
    void render();
    void pollEvents();
    void particleFactory(float pos_x, float pos_y, float vel_x, float vel_y, float radius, int num_particles);


};

#endif