#include "Solver.hpp"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <chrono>

Solver::Solver(/* args */) {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            for(int k = 0; k < DELTA_T; k++) {
                this->data[i][j][k] = 0;
            }   
        }  
    } 
}

Solver::~Solver() {
}

/* Public functions */

void Solver::simulation_of_order(int n) {
    std::cout << "Starting " << n << " iterations...\n" << std::endl;
    auto t0 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < n; i++) {
        if(i%100 == 0) {std::cout << "Iteration number " << i << " starting..." << std::endl;}
        this->iteration();
    }
    auto t1 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t1-t0);
    std::cout << "Time spent : " << float(duration.count())/float(1000000) << " s" << std::endl;
}

/* Private functions */
///*
bool Solver::is_on_bound(int i, int j, int k) {
    return i == 0 or i == L-1 or j == 0 or j == L-1 or k == 0;
}

double Solver::boundary(int i, int j, int k) {
    if (i == 0 or i == L-1) return cos(3.14159*double(j)/double(L))*cos(3.14159*double(j)/double(L));

    else if(k == 0) return 0;

    else if (j == 0 or j == L-1) return 0;

    else {
        std::cout << "Problème !!!!" << std::endl;
        return 10000;
    }
}//*/

/*
bool Solver::is_on_bound(int i, int j, int k) {
    return i == 0 or i == L-1 or k == 0;
}

double Solver::boundary(int i, int j, int k) {
    if (i == 0) return 1;

    else if (i == L-1) return 0;

    else if(k == 0) return 0;

    else if (j == 0 or j == L-1) return 0;

    else {
        std::cout << "Problème !!!!" << std::endl;
        return 1000000;
    }
}//*/

void Solver::update_at(int i, int j, int k) {
    if(this->is_on_bound(i, j, k)) this->data[i][j][k] = this->boundary(i, j, k);
    else {
        this->data[i][j][k] = ALPHA*(this->data[i-1][j][k] + this->data[i+1][j][k] + this->data[i][j-1][k] + this->data[i][j+1][k]) + BETA*this->data[i][j][k-1];
    }
}

void Solver::iteration() {
    for(int i = 0; i < L; i++) {
        for(int j = 0; j < L; j++) {
            for(int k = 0; k < DELTA_T; k++) {
                this->update_at(i, j, k);
            }
        }
    } 
}
