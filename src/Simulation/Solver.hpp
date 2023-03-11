#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "Params.hpp"

class Solver {
public:
    Solver();
    virtual ~Solver();

    double data[L][L][DELTA_T];

    void simulation_of_order(int n);
    void iteration();

private:
    bool is_on_bound(int i, int j, int k);
    double boundary(int i, int j, int k);
    void update_at(int i, int j, int k);
};

#endif