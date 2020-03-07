#pragma once
#include<vector>
#include<iostream>
#include<string>
#include<fstream>
class Vecteur{
    private:
       unsigned int N_;
       std::vector<double> coef_;
    public:
       Vecteur ();
       Vecteur (int N);
       Vecteur (int N, double b);
       Vecteur (const Vecteur &v);
       Vecteur (std::string N);
       ~Vecteur()=default;
       unsigned int size() const;
       double & operator() (int i);
       double operator() (int i) const;
};

std::ostream & operator << (std::ostream &os, const Vecteur& v);
Vecteur operator+(const Vecteur &v,const Vecteur &w);
Vecteur operator-(const Vecteur &v,const Vecteur &w);
double operator*(const Vecteur &v,const Vecteur &w);
Vecteur operator*(const Vecteur &v,double w);
Vecteur operator*(double w, const Vecteur &v);
