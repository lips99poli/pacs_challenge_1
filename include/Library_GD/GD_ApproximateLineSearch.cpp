#include "GD_ApproximateLineSearch.hpp"

void GD_ApproximateLineSearch::update_alpha(){
    while(not_check_alpha()) { alpha_k /= 2; }
};

bool GD_ApproximateLineSearch::not_check_alpha() const{
    Point new_point = x_k;
    for (std::size_t i=0; i<x_k.size(); ++i){
        new_point[i] -= alpha_k * gf(x_k)[i];
    }
    return f(x_k)-f(new_point) <= par.sigma * alpha_k * std::pow(compute_norm<norm>(gf(x_k)),2);
};
