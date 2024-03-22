#include "Minimizer.hpp"

Real Minimizer::compute_norm(const Point& p) const{
    Real norm(0.);
    for(const auto& coordinate : p){
        norm += coordinate*coordinate;
    }
    return std::sqrt(norm);
}

bool Minimizer::not_check_alpha(const F& f, const GF& gf) const{
    Point new_point = x_k;
    for (std::size_t i=0; i<x_k.size(); ++i){
        new_point[i] -= alpha_k * gf(x_k)[i];
    }
    return f(x_k)-f(new_point) <= par.sigma*alpha_k*std::pow(compute_norm(gf(x_k)),2);
}

bool Minimizer::update_alpha(const F& f, const GF& gf) {
    while(not_check_alpha(f,gf)) { alpha_k /= 2; }
    return true;
}

Real Minimizer::update_new_point(const F& f, const GF& gf, Point& new_point) const{

    Real step_lenght(0.);

    for(std::size_t i=0; i<x_k.size(); ++i){

        new_point[i] -= alpha_k * gf(x_k)[i];
        step_lenght += (new_point[i]-x_k[i])*(new_point[i]-x_k[i]);

    }
    return std::sqrt(step_lenght);
}

void Minimizer::find_minimum(const F& f, const GF& gf){
    bool continue_condition = true;
    Point new_point(x_k);
    std::size_t k=0;

    for(; continue_condition && update_alpha(f,gf); ++k){
        new_point = x_k;
        Real step_length = update_new_point(f,gf, new_point);
        continue_condition = k<par.max_it && step_length>par.epsilon_s && std::abs(f(new_point)-f(x_k))>par.epsilon_r;
        x_k = new_point;
    }
    std::cout<<"number of it: "<<k<<std::endl;
}

Point Minimizer::get_minimum() const{
    return x_k;
}

void Minimizer::print_info() const{
    std::cout << "Last alpha_k is: " << alpha_k << std::endl;
    std::cout << "The coordinate of the minimum are: " << x_k.size() << std::endl;
    for(const auto& coordinate : x_k){
        std::cout << coordinate << std::endl;
    }
}