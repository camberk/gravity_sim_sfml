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

void Particle::render(sf::RenderTarget& target) {
    this->particleShape.setPosition(this->pos);
    target.draw(this->particleShape);
}

void Particle::updatePhysics(Source &source) {
    float distance_x = source.getPos().x - this->pos.x;
    float distance_y = source.getPos().y - this->pos.y;
    float distance = sqrt(distance_x * distance_x + distance_y * distance_y);
    float inverse_distance = 1.f / distance;
    float inverse_distance_squared = inverse_distance * inverse_distance;
    float normalized_x = distance_x * inverse_distance;
    float normalized_y = distance_y * inverse_distance;
    float acceleration_x = normalized_x * source.getStrength() * inverse_distance_squared;
    float acceleration_y = normalized_y * source.getStrength() * inverse_distance_squared;
    this->vel.x += acceleration_x;
    this->vel.y += acceleration_y;
    this->pos.x += this->vel.x;
    this->pos.y += this->vel.y;
    std::cout << std::endl;
    std::cout << "This Update Start" << std::endl;
    std::cout << "vel x: " << this->vel.x << std::endl;
    std::cout << "vel y: " << this->vel.y << std::endl;
    std::cout << "pos x: " << this->pos.x << std::endl;
    std::cout << "pos y: " << this->pos.y << std::endl;
    std::cout << "This Update End" << std::endl;
    std::cout << std::endl;
}

sf::Vector2f Particle::get_pos() {
    return this->pos;
}


sf::Vector2f Particle::get_vel() {
    return this->vel;
}