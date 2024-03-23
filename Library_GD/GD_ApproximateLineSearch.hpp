#ifndef GD_APPROXIMATE_LINE_SEARCH
#define GD_APPROXIMATE_LINE_SEARCH

#include "GD_Abstract.hpp"

class GD_ApproximateLineSearch : public GD_Abstract{

    virtual void update_alpha() override;
    bool not_check_alpha() const;

    public:
    GD_ApproximateLineSearch(const Parameters& par, const F& f, const GF& gf):
        GD_Abstract(par,f,gf){};

};

#endif