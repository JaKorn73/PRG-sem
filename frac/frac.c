/*
 * filename: frac.c
 * date: 2024/05/01 16:49 
 * author: Jakub Kornel
 * email: kornejak@fel.cvut.cz
*/
#include "frac.h"

#include <stdio.h>
#include <complex.h>

int count_convergence(double complex num, double complex comp_const, int max_steps)
{
  for (int i = 0; i < max_steps; i++) {
    num = num * num + comp_const;
    if (cabs(num) > 2)
      return i;
  }
  return -1;

}
