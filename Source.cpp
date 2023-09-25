#include "Source.h"

Source::Source(float pos_x, float pos_y, float strength, float radius) {
    this->pos = sf::Vector2f(pos_x, pos_y);
    this->strength = strength;
    this->sourceShape = sf::CircleShape();
    this->sourceShape.setPosition(this->pos);
    this->sourceShape.setFillColor(sf::Color::Cyan);
    this->sourceShape.setRadius(radius);
}

Source::~Source() {}

void Source::render(sf::RenderTarget& target) {
    target.draw(this->sourceShape);
}

sf::Vector2f Source::getPos() {
    return this->pos;
}

float Source::getStrength() {
    return this->strength;
}