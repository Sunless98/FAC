#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
class Matrice{
    private:
    unsigned int N_;
    std::vector<double> coef_;
    bool LU;
    public:
    Matrice():N_(0),coef_(0),LU(false){}
    Matrice(unsigned int N):N_(N),coef_(N*N,0),LU(false){}
    Matrice(std::string);
    Matrice (const Matrice & M):N_(M.N_),coef_(M.coef_),LU(false){}
    ~Matrice() = default;
    void MLaplacien(unsigned int N);
    unsigned int size() const {return N_;}
    double & operator() (int i,int j){return coef_[N_*i+j];}
    double operator() (int i, int j) const {return coef_[N_*i+j];}
    void decomp_LU();
    void decomp_Cholesky();
};

std::ostream & operator<<(std::ostream & os, const Matrice &A);
Matrice operator+(const Matrice &v,const Matrice &w);
Matrice operator-(const Matrice &v,const Matrice &w);
Matrice operator*(const Matrice &v,const Matrice &w);
Matrice operator*(const Matrice &v,double w);
Matrice operator*(double w,const Matrice &v);