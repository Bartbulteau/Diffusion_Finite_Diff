#include "UI.hpp"

UI::UI(float h): time(0) {

    std::cout << "Starting simulation..." << std::endl;
    this->solver = new Solver();
    this->solver->simulation_of_order(N);
    std::cout << "Done !" << std::endl;

    this->videoMode.width = L*h;
    this->videoMode.height = L*h;
    this->window = new sf::RenderWindow(this->videoMode, "LaplaceDiffFinies", sf::Style::Default);
    this->window->setFramerateLimit(FRAME_RATE);

    this->squares = new Square**[L];
    for(int i = 0; i < L; i++) this->squares[i] = new Square*[L];
    for(int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            this->squares[i][j] = new Square(i, j, sf::Color::White, h);
        }
    }
}

UI::~UI() {
    delete this->window;
    for(int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            delete this->squares[i][j];
        }
    }
    for(int i = 0; i < L; i++) delete this->squares[i];
}

const bool UI::getWindowIsOpen() const {
    return this->window->isOpen();
}

void UI::pollEvents() {
    while(this->window->pollEvent(this->ev)) {
        switch (this->ev.type) {
                
            // Window closing
            case sf::Event::Closed:
                this->window->close();
                break;
            default:
                break;
        }
    }
}

void UI::update() {
    this->pollEvents();
    if(this->time < DELTA_T) this->time++;
    else this->time = 0;
}

void UI::render() {
    this->window->clear(sf::Color::White);
    this->drawSimulation(this->time);
    this->window->display();
}

void UI::drawSimulation(int t) {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            this->squares[i][j]->setColor(sf::Color{static_cast<sf::Uint8>(255*this->solver->data[i][j][t]), 0, 0});
            this->window->draw(this->squares[i][j]->shape);
        }
    }
}

uint32_t UI::rgb(double ratio) {
    //we want to normalize ratio so that it fits in to 6 regions
    //where each region is 256 units long
    int normalized = int(ratio * 256 * 6);

    //find the region for this position
    int region = normalized / 256;

    //find the distance to the start of the closest region
    int x = normalized % 256;

    uint8_t r = 0, g = 0, b = 0;
    switch (region)
    {
    case 0: r = 255; g = 0;   b = 0;   g += x; break;
    case 1: r = 255; g = 255; b = 0;   r -= x; break;
    case 2: r = 0;   g = 255; b = 0;   b += x; break;
    case 3: r = 0;   g = 255; b = 255; g -= x; break;
    case 4: r = 0;   g = 0;   b = 255; r += x; break;
    case 5: r = 255; g = 0;   b = 255; b -= x; break;
    }
    return r + (g << 8) + (b << 16);
}