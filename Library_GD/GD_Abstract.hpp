#ifndef GD_ABSTRACT
#define GD_ABSTRACT

#include "Utilities.hpp"

class GD_Abstract {
    protected: 
    const Parameters par;
    Real alpha_k;
    Point x_k;
    Point next_point;
    F f;
    GF gf;
    std::size_t k=0;

    virtual void update_alpha()=0;
    bool check_conditions() const;

    void update_next_point();

    public:
    GD_Abstract(const Parameters& par, const F& f, const GF& gf):
        par(par),
        alpha_k(par.alpha0),
        x_k(par.starting_point),
        f(f),
        gf(gf)
        {
            next_point.resize(x_k.size(),0.);
        };

    virtual void find_minimum();
    Point get_minimum() const;
    void print_results(std::ostream& output = std::cout) const;
};

#endif