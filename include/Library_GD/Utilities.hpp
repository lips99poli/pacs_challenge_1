#ifndef UTILITIES
#define UTILITIES

#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include "GetPot"

using Real = double;
using Point = std::vector<Real>;
using F = std::function<Real (Point)>;
using GF = std::function<Point (Point)>;

struct Parameters {
    Point starting_point;
    Real epsilon_s = 1e-6;
    Real epsilon_r = 1e-6;
    Real max_it = 100000;
    Real alpha0 = 1;
    Real sigma = 0.49;

    Parameters(int argc, char** argv, const Point& sp) : starting_point(sp) {
        GetPot command_line(argc, argv);
        const std::string filename = command_line.follow("parameters", 2, "-f", "--file");
        GetPot datafile(filename.c_str());
        epsilon_s = datafile("epsilon_s",1e-6);
        epsilon_r = datafile("epsilon_r",1e-6);
        max_it = datafile("max_it",100000);
        alpha0 = datafile("alpha0",1);
        sigma = datafile("sigma",0.49);
    }
};

enum norm_type{
    norm = 0,
    distance = 1,
};

#endif

template <norm_type nt>
Real compute_norm(const Point& p1, const Point& p2={}){
    Real norm(0.);
    if constexpr (nt==0){
        for(const auto& coordinate : p1){
            norm += coordinate*coordinate;
        }
    }
    else{
        for(std::size_t i=0; i<p1.size(); ++i){
            norm += (p1[i]-p2[i])*(p1[i]-p2[i]);
        }
    }
    return std::sqrt(norm); 
}