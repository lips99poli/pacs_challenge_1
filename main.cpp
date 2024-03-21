#include "Minimizer.hpp"
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

int main(){
    Point prova(2,1.);
    std::cout << prova[0] << prova[1] << prova.size() << std::endl;
    Parameters par;
    Minimizer gradient_descent(par);
    gradient_descent.find_minimum(f,gf);

    Point minimum = gradient_descent.get_minimum();
    gradient_descent.print_info();
}