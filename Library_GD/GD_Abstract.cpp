#include "GD_Abstract.hpp"

bool GD_Abstract::check_conditions() const{

    Real step_length = compute_norm<distance>(x_k,next_point);
    Real residual = std::abs(f(next_point)-f(x_k));

    return (k<par.max_it && step_length>=par.epsilon_s && residual>=par.epsilon_r);
}

void GD_Abstract::find_minimum(){
    k = 0;
    //first iteration
    update_next_point();
    //algorithm_loop (1st iteration already done)
    for(;check_conditions();++k){
        x_k = next_point;
        update_alpha();
        update_next_point();
    }
    x_k = next_point;
}

void GD_Abstract::update_next_point(){
    for(std::size_t i=0; i<x_k.size(); ++i){
        next_point[i] -= alpha_k * gf(x_k)[i];
    }
}

void GD_Abstract::print_results(std::ostream& output) const{
    output << "Number of iteration performed: " << k << std::endl;
    output << "The coordinate of the minimum are:" << std::endl; 
    for(auto cit=x_k.cbegin(); cit!=x_k.cend(); ++cit){
        output << *cit << std::endl;
    }
}