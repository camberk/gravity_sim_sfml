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

class Sim
{
private:
    sf::RenderWindow* window;
    sf::Event sfmlEvent;
    Particle shape;
    Source s_shape;

    void initVars();
public:
    Sim();
    ~Sim();

    void run();

    void update();
    void render();
    void pollEvents();


};

#endif