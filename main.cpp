
#include "./Library_GD/GD_ApproximateLineSearch.hpp"
#include "./Library_GD/GD_InverseDecay.hpp"
#include "./Library_GD/GD_ExponentialDecay.hpp"
#include <iostream>
#include <cmath> 

Real f (const Point& x){
    return x[0]*x[1] + 4*x[0]*x[0]*x[0]*x[0] + x[1]*x[1] + 3*x[0];
}
Point gf (const Point& x){
    Point gf_x(x.size());
    gf_x[0] = x[1] + 16*x[0]*x[0]*x[0] + 3;
    gf_x[1] = x[0] + 2*x[1];
    return gf_x;
}

int main(int argc, char** argv){

    Parameters par(argc,argv,{0,0});

    std::cout << "Gradient descent with Approximate Line Search: " << std::endl;
    GD_ApproximateLineSearch ALS_Ajirno(par,f,gf);
    ALS_Ajirno.find_minimum();
    ALS_Ajirno.print_results();

    // Ho osservato che con alpha0=1 gli algoritmi di InverseDecay e ExponentialDecay la soluzione diverge, quindi lo abbasso a 0.2
    par.alpha0 = 0.2;
    std::cout << "\nNew alpha0: " << par.alpha0 << std::endl;
    
    std::cout << "\nGradient descent with Inverse Decay: " << std::endl;
    GD_InverseDecay ID(par,f,gf,0.2);
    ID.find_minimum();
    ID.print_results();

    std::cout << "\nGradient descent with Exponential Decay: " << std::endl;
    GD_ExponentialDecay ED(par,f,gf,0.2);
    ED.find_minimum();
    ED.print_results();
}