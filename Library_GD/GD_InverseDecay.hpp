#ifndef GD_INVERSE_DECAY
#define GD_INVERSE_DECAY

#include "GD_Abstract.hpp"

class GD_InverseDecay : public GD_Abstract{

    Real mu=0.2;

    virtual void update_alpha() override;

    public:
    GD_InverseDecay(const Parameters& par, const F& f, const GF& gf, Real mu):
        GD_Abstract(par,f,gf), mu(mu){};
};

#endif