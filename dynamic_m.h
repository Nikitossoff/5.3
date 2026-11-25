#ifndef DYNAMIC_M_H
#define DYNAMIC_M_H

#include <stdio.h>

void VvodMatr(int ***x, int n, int m, FILE *in);
void Vivod(FILE *out, int **x, int n, int m);
float sr_arifm(int **x, int n, int m);
int kol_otr_stolb(int **x, int n, int j);
int nom_max_otr_stolb(int **x, int n, int m);
void zamena_stolb(int **x, int n, int j);
void zamena_matr(int **x, int n, int m, int start_j);
void Ochistka(int ***x, int n);

#endif
