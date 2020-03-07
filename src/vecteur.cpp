#include "../include/vecteur.hpp"
Vecteur::Vecteur() : N_(0), coef_(0) {}

Vecteur::Vecteur (int N):N_(N), coef_(N) {}

Vecteur::Vecteur(int N,double x) : N_(N), coef_(N,x){}

Vecteur::Vecteur(const Vecteur &v) : N_(v.size()), coef_(v.coef_) {}

unsigned int Vecteur::size() const {return N_;}

double & Vecteur::operator() (int i) {return coef_[i];}

double Vecteur::operator() (int i) const {return coef_[i];}

std::ostream & operator<<(std::ostream &os, const Vecteur& v){
    for(unsigned int i=0; i<v.size();i++){
        os << v(i)<<" ";
        os<< std::endl;
    }
    return os;
}
Vecteur operator+(const Vecteur &v, const Vecteur&w){
    Vecteur x(v.size());
    if (v.size()==w.size()){
        for(unsigned i=0;i<v.size();i++){
            x(i)=v(i)+w(i);
        }
    }
    else {std::cout<<"Erreur tailles des vecteurs";}
    return x;
}
Vecteur operator-(const Vecteur &v, const Vecteur&w){
    Vecteur x(v.size());
    if (v.size()==w.size()){
        for(unsigned int i=0;i<v.size();i++){
            x(i)=v(i)-w(i);
        }
    }
    else {std::cout<<"Erreur tailles des vecteurs";}
    return x;
}
double operator*(const Vecteur &v, const Vecteur&w){
    Vecteur x(v.size());
    int j=0;
    if (v.size()==w.size()){
        for(unsigned int i=0;i<v.size();i++){
            j+=v(i)*w(i);
        }
    }
    else {std::cout<<"Erreur tailles des vecteurs";}
    return j;
}
Vecteur operator*(double w, const Vecteur &v){
    Vecteur x(v.size());
    for(unsigned int i=0;i<v.size();i++){
        x(i)=v(i)*w;
    }
    return x;
}
Vecteur operator*(const Vecteur &v, double w){
    Vecteur x(v.size());
    for(unsigned int i=0;i<v.size();i++){
        x(i)=v(i)*w;
    }
    return x;
}
Vecteur::Vecteur(std::string N){
    std::ifstream source(N);
    unsigned int n;
    source >> n;
    N_= n;
    std::vector<double> c(n,0);
    coef_=c;
    int i;
    double x;
    while (source >> i >> x) {
        coef_[i]=x;
    }
    source.close();
}