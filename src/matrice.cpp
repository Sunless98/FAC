#include "../include/matrice.hpp"
std::ostream & operator<<(std::ostream & os, const Matrice &A){
    for(unsigned int i=0;i<A.size();i++){
        for(unsigned int j=0; j<A.size();j++){
            os<<A(i,j)<<" ";
        }
        os<<std::endl;
    }
return os;
}
Matrice operator+(const Matrice &v,const Matrice &w){
    Matrice z(v.size());
    if(v.size()==w.size()){
        for(unsigned i=0;i<v.size();i++){
            for(unsigned j=0;j<v.size();j++){
                z(i,j)=v(i,j)+w(i,j);
            }
        }
    }
    else{std::cout<<"Erreur tailles des matrices";}
return z;}
Matrice operator-(const Matrice &v,const Matrice &w){
    Matrice z(v.size());
    if(v.size()==w.size()){
        for(unsigned i=0;i<v.size();i++){
            for(unsigned j=0;j<v.size();j++){
                z(i,j)=v(i,j)-w(i,j);
            }
        }
    }
    else{std::cout<<"Erreur tailles des matrices";}
return z;}
Matrice operator*(const Matrice &v,const Matrice &w){
    Matrice z(v.size());
    if(v.size()==w.size()){
        for(unsigned i=0;i<v.size();i++){
            for(unsigned j=0;j<v.size();j++){
                for(unsigned k=0; k<v.size();k++){
                    z(i,j)+=v(i,k)*w(k,j);
                }
            }
        }
    }
    else{std::cout<<"Erreur tailles des matrices";}
return z;}
Matrice operator*(const Matrice &v,double w){
    Matrice z(v.size());
    for(unsigned i=0;i<v.size();i++){
        for(unsigned j=0;j<v.size();j++){
            z(i,j)=v(i,j)*w;
        }
    }
return z;}
Matrice operator*(double w,const Matrice &v){
    Matrice z(v.size());
    for(unsigned i=0;i<v.size();i++){
        for(unsigned j=0;j<v.size();j++){
            z(i,j)=v(i,j)*w;
        }
    }
return z;}
Matrice::Matrice(std::string N){
    std::ifstream source(N);
    unsigned int n;
    source >> n;
    N_= n;
    std::vector<double> c(n*n);
    coef_=c;
    int i,j;
    double x;
    while (source >> i >> j >> x) {
        coef_[N_*i+j]=x;
    }
    source.close();
    LU=false;
}
void Matrice::MLaplacien(unsigned int N){
    N_=N;
    std::vector<double> c(N*N);
    coef_=c;
    for (unsigned int i=0;i<N-1;i++){
        coef_[N*i+i]=2;
        coef_[N*i+i+1]=-1;
        coef_[N*(i+1)+i]=-1;
    }
    coef_[N*(N-1)+N-1]=2;
return;
}
void Matrice::decomp_LU(){
    double pivot;
    if(LU==false){
        for (unsigned int k=0;k<N_;k++){
            pivot = coef_[N_*k+k];
            for (unsigned int i=k+1;i<N_;i++){
                coef_[N_*i+k]=coef_[N_*i+k]/pivot;
                for (unsigned int j=k+1;j<N_;j++){
                    coef_[N_*i+j]-=coef_[N_*i+k]*coef_[N_*k+j];
                }
            }
        }
        LU=true;
    }
}

void Matrice::decomp_Cholesky(){
    double pivot;
    if(LU==false){
        for(unsigned int k=0;k<N_;k++){
            pivot=sqrt(coef_[N_*k+k]);
            coef_[N_*k+k]=sqrt(coef_[N_*k+k]);
            for(unsigned int i=k+1;i<N_;i++){
                coef_[N_*i+k]=coef_[N_*i+k]/pivot;
                coef_[N_*k+i]=coef_[N_*i+k];
                for(unsigned int j=k+1;j<N_;j++){
                    coef_[N_*i+j]-=coef_[N_*i+k]*coef_[N_*j+k];
                }
            }
        }
    LU=true;}
}