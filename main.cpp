#include "src/UI/UI.hpp"
#include "src/Simulation/Params.hpp"
#include <iostream>

int main(int argc, char** argv) {
    UI ui(H_PARAM);
    
    while (ui.getWindowIsOpen()) {
        ui.update();
        ui.render();
    }

    return 0;
}
