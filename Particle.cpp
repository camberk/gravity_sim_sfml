#include "Particle.h"

Particle::Particle(float pos_x, float pos_y, float vel_x, float vel_y, float radius) {
    this->pos = sf::Vector2f(pos_x, pos_y);
    this->vel = sf::Vector2f(vel_x, vel_y);
    this->particleShape = sf::CircleShape();
    this->particleShape.setPosition(this->pos);
    this->particleShape.setFillColor(sf::Color::White);
    this->particleShape.setRadius(radius);
}

Particle::~Particle() {}