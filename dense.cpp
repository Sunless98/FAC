#include "include/vecteur.hpp"
#include "include/matrice.hpp"
#include "include/direct_solvers.hpp"
#include<iostream>
int main(){
    Matrice A(5);
    A.MLaplacien(5);
    std::cout<<A<<std::endl;
    A.decomp_Cholesky();
    std::cout<<A<<std::endl;
    Vecteur b(5,1);
    Vecteur X(5);
    X=solve_triang_inf(A,b);
    X=solve_triang_sup(A,X);
    std::cout<<X<<std::endl;
    return 0;
}