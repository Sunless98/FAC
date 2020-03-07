#pragma once
#include "matrice.hpp"
#include "vecteur.hpp"
Vecteur solve_diag(const Matrice &A, const Vecteur &b);
Vecteur solve_triang_inf(const Matrice &A, const Vecteur &b);
Vecteur solve_triang_sup(const Matrice &A, const Vecteur &b);
Vecteur solve_triang_inf_id(const Matrice &A, const Vecteur &b);
Vecteur solve_triang_sup_id(const Matrice &A, const Vecteur &b);
