#include "Square.hpp"

// Constructor / Destructor
Square::Square(int x, int y, sf::Color color, float h) : h(h) {
    this->setPosition(x, y);
    this->setColor(color);
}

Square::~Square() {
    
}

// Getters

// Setters
void Square::setPosition(int x, int y) {
    shape.setPosition(x*h, y*h);
    shape.setSize(sf::Vector2f(h, h));
}

void Square::setColor(sf::Color color) {
    shape.setFillColor(color);
}