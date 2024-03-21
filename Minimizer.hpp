#ifndef MINIMIZER
#define MINIMIZER

#include <iostream>
#include <vector>
#include <functional>
#include <cmath>

using Real = double;
using Point = std::vector<Real>;
using F = std::function<Real (Point)>;
using GF = std::function<Point (Point)>;


struct Parameters {
    Point starting_point;
    double epsilon_s = 1e-4;
    double epsilon_r = 1e-4;
    double max_it = 10000;
    Real alpha0 = 1;
    Real sigma = 0.49;

    Parameters() : starting_point(2, 1.0) {}
};

class Minimizer {
    private: 
    Parameters par;
    Real alpha_k;
    Point x_k;

    Real compute_norm(const Point&) const;
    
    bool update_alpha(const F& f, const GF& gf);

    bool not_check_alpha(const F& f, const GF& gf) const;

    Real update_new_point(const F& f, const GF& gf, Point& new_point) const;

    public:
    Minimizer(const Parameters& par):
        par(par),
        alpha_k(par.alpha0),
        x_k(par.starting_point){};

    void find_minimum(const F& f, const GF& gf);

    Point get_minimum() const;

    void print_info() const;
};

#endif