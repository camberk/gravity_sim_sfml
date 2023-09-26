#include "Sim.h"

void Sim::initVars() {
    this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "sim", sf::Style::Close | sf::Style::Titlebar);
    // this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "sim", sf::Style::Close | sf::Style::Titlebar | sf::Style::Fullscreen);
    this->max_screen_dim_x = this->window->getSize().x;
    this->max_screen_dim_y = this->window->getSize().y;
    float x_mid = this->max_screen_dim_x / 2;
    float y_mid = this->max_screen_dim_y / 2;
    this->source_shape = Source(x_mid, y_mid, 7000.f, 40.f);
    this->particleFactory(x_mid, y_mid + 450, 2.f, 0.f, 10.f, 1);
    this->window->setFramerateLimit(120); // limit the framereate
}

/*
Particle takes position x and y, velocity x and y, and radius
Source takes position x and y, gravity strength, and radius
*/
Sim::Sim() : source_shape(Source(0.f, 0.f, 0.f, 0.f))
{
    this->initVars();
}

Sim::~Sim()
{
    for(size_t i = 0; i < this->particles.size(); i++) {
        delete particles[i];
    }
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
    for(size_t i = 0; i < this->particles.size(); i++) {
        particles[i]->updatePhysics(this->source_shape);
    }
}

void Sim::render() {
    this->window->clear();

    this->source_shape.render(*this->window);
    for(size_t i = 0; i < this->particles.size(); i++) {
        particles[i]->render(*this->window);
    }

    this->window->display();
}

void Sim::particleFactory(float pos_x, float pos_y, float vel_x, float vel_y, float radius, int num_particles) {
    Rng rng = Rng(30);
    for(size_t i = 0; i < num_particles; ++i) {
        if(i != 0) {
            pos_x += rng.getRandomNumber();
            pos_y += 10;
        }
        particles.push_back(new Particle(pos_x, pos_y, vel_x, vel_y, radius));
    }
    
}