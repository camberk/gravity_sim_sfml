#include "Sim.h"

void Sim::initVars() {
    this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "sim", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60); // limit the framereate
}

/*
Particle takes position x and y, velocity x and y, and radius
Source takes position x and y, gravity strength, and radius
*/
Sim::Sim() : shape(Particle(600.f, 700.f, 5.f, 0.f, 20.f)), s_shape(Source(800.f, 500.f, 6000.f, 40.f))
{
    this->initVars();
}

Sim::~Sim()
{
    delete this->window;
}

void Sim::run() {
    while(this->window->isOpen()) {
        this->update();
        this->render();
        
    }
}

void Sim::pollEvents() {
    while(this->window->pollEvent(this->sfmlEvent)) {
        switch (this->sfmlEvent.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if(this->sfmlEvent.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                }
                break;
        }
    }
}

void Sim::update() {
    this->pollEvents();
    this->shape.updatePhysics(this->s_shape);
}

void Sim::render() {
    this->window->clear();

    this->shape.render(*this->window);
    this->s_shape.render(*this->window);


    this->window->display();
}