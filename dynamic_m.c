#include "dynamic_m.h"
#include <malloc.h>
#include <stdlib.h>

void VvodMatr(int ***x, int n, int m, FILE *in) {
    *x = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        (*x)[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            fscanf(in, "%i", &(*x)[i][j]);
        }
    }
    return;
}

void Vivod(FILE *out, int **x, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(out, "%4i ", x[i][j]);
        }
        fprintf(out, "\n");
    }
    fprintf(out, "\n");
    return;
}

float sr_arifm(int **x, int n, int m) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            s += x[i][j];
        }
    }
    float sr = (float)s / (n * m);
    return sr;
}

int kol_otr_stolb(int **x, int n, int j) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (x[i][j] < 0) {
            k++;
        }
    }
    return k;
}

int nom_max_otr_stolb(int **x, int n, int m) {
    int max_k = kol_otr_stolb(x, n, 0);
    int max_j = 0;
    for (int j = 1; j < m; j++) {
        int k = kol_otr_stolb(x, n, j);
        if (k > max_k) {
            max_k = k;
            max_j = j;
        }
    }
    if (max_k == 0) {
        max_j = -1;
    }
    return max_j;
}

void zamena_stolb(int **x, int n, int j) {
    for (int i = 0; i < n; i++) {
        if (x[i][j] < 0) {
            x[i][j] = abs(x[i][j]);
        }
    }
    return;
}

void zamena_matr(int **x, int n, int m, int start_j) {
    for (int j = start_j + 1; j < m; j++) {
        zamena_stolb(x, n, j);
    }
    return;
}

void Ochistka(int ***x, int n) {
    for (int i = 0; i < n; i++) {
        free((*x)[i]);
    }
    free((*x));
    return;
}
