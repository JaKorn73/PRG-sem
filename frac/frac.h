/*
 * filename: frac.h
 * date: 2024/05/01 16:49 
 * author: Jakub Kornel
 * email: kornejak@fel.cvut.cz
*/
#include <complex.h>

// returns -1 if not converging or k if converging
int count_convergence(double complex num, double complex comp_const, int max_steps);
