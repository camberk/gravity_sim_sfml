#ifndef SIM_H
#define SIM_H

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Sim
{
private:
    sf::RenderWindow* window;
    sf::Event sfmlEvent;

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