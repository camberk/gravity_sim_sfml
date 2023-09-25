#ifndef PARTICLE_H
#define PARTICLE_H

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <cmath>
#include <iostream>
#include "Source.h"


class Particle {
    private:
        sf::Vector2f pos;
        sf::Vector2f vel;
        sf::CircleShape particleShape;


    public:
        Particle(float pos_x, float pos_y, float vel_x, float vel_y, float radius);
        ~Particle();

        void render(sf::RenderTarget& target);
        void updatePhysics(Source &source);

        
};

#endif
