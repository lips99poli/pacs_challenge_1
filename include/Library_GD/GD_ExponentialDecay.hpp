#ifndef EXPONENTIAL_DECAY
#define EXPONENTIAL_DECAY

#include "GD_Abstract.hpp"

class GD_ExponentialDecay : public GD_Abstract{

    Real mu=0.2;

    virtual void update_alpha() override;

    public:
    GD_ExponentialDecay(const Parameters& par, const F& f, const GF& gf, Real mu):
        GD_Abstract(par,f,gf), mu(mu){};
};

#endif