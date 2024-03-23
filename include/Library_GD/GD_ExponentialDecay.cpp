#include "GD_ExponentialDecay.hpp"

void GD_ExponentialDecay::update_alpha(){
    alpha_k = par.alpha0 * std::exp(-mu*k);
    //alpha_k *= std::exp(-mu*k);
}

