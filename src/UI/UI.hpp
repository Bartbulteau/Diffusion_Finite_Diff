#ifndef UI_HPP
#define UI_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Square.hpp"
#include "../Simulation/Solver.hpp"
#include "../Simulation/Params.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class UI {
public:
    UI(float h);
    virtual ~UI();

    const bool getWindowIsOpen() const;
    void update();
    void render();
    void pollEvents();

    uint32_t rgb(double ratio);

private:

    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    Square*** squares;
    Solver* solver;

    void drawSimulation(int t);

    int time;
};

#endif