#ifndef SOURCE_H
#define SOURCE_H

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Source
{
    private:
        sf::Vector2f pos;
        float strength;
        sf::CircleShape sourceShape;

        
    public:
        Source(float pos_x, float pos_y, float strength, float radius);
        ~Source();
        
        void render(sf::RenderTarget& target);
        sf::Vector2f getPos();
        float getStrength();

};

#endif