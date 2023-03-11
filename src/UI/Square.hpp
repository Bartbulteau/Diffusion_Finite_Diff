#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <SFML/Graphics.hpp>

class Square {
public:
    // Constructor / Destructor
    Square(int x, int y, sf::Color color, float h);
    virtual ~Square();
    
    // Getters
    
    // Setters
    void setPosition(int x, int y);
    void setColor(sf::Color color);

    sf::RectangleShape shape;
    
private:
    // Private variables
    float h;
    // Private functions
};

#endif