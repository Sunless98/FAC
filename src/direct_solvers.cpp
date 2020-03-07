#include "../include/direct_solvers.hpp"

Vecteur solve_diag(const Matrice &A, const Vecteur &b){
    Vecteur X(b.size());
    for (unsigned int i=0; i<b.size(); i++){
        X(i)=b(i)/A(i,i);
    }
    return X;
}

Vecteur solve_triang_inf(const Matrice &A, const Vecteur &b){
    Vecteur X(b.size());
    for (unsigned int i=0; i<b.size();i++){
        X(i)=b(i);
        for (unsigned int j=0; j<i;j++){
            X(i)-=A(i,j)*X(j);
        }
        X(i)=X(i)/A(i,i);
    }
    return X;
}

Vecteur solve_triang_sup(const Matrice &A, const Vecteur &b){
    unsigned int n;
    n=b.size();
    Vecteur X(n);
    for (unsigned int i=0; i<n;i++){
        X(n-i-1)=b(n-i-1);
        for (unsigned int j=n-i; j<n;j++){
            X(n-i-1)-=A(n-i-1,j)*X(j);
        }
        X(n-i-1)=X(n-i-1)/A(n-i-1,n-i-1);
    }
    return X;
}

Vecteur solve_triang_inf_id(const Matrice &A, const Vecteur &b){
    Vecteur X(b.size());
    for (unsigned int i=0; i<b.size();i++){
        X(i)=b(i);
        for (unsigned int j=0; j<i;j++){
            X(i)-=A(i,j)*X(j);
        }
    }
    return X;
}

Vecteur solve_triang_sup_id(const Matrice &A, const Vecteur &b){
    unsigned int n;
    n=b.size();
    Vecteur X(n);
    for (unsigned int i=0; i<n;i++){
        X(n-i-1)=b(n-i-1);
        for (unsigned int j=n-i; j<n;j++){
            X(n-i-1)-=A(n-i-1,j)*X(j);
        }
    }
    return X;
}


