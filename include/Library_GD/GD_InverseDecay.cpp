#include "GD_InverseDecay.hpp"

void GD_InverseDecay::update_alpha(){
    alpha_k = par.alpha0/(1+mu*k);
    //alpha_k /= (1+mu*k);
}

