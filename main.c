#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include "dynamic_m.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    setlocale(LC_NUMERIC, "C");

    FILE *in = fopen("t1.txt", "r");

    int n, m;
    do {
        printf("Введите количество строк N: ");
        scanf("%i", &n);
        if (n <= 1 || n > 100) {
            printf("Ошибка! N должно быть больше 1 и не больше 100.\n");
        }
    } while (n <= 1 || n > 100);

    do {
        printf("Введите количество столбцов M: ");
        scanf("%i", &m);
        if (m <= 1 || m > 100) {
            printf("Ошибка! M должно быть больше 1 и не больше 100.\n");
        }
    } while (m <= 1 || m > 100);

    int **A;
    VvodMatr(&A, n, m, in);
    fclose(in);

    FILE *out = fopen("output.txt", "w");

    fprintf(out, "Исходная матрица A:\n");
    Vivod(out, A, n, m);

    float sr1 = sr_arifm(A, n, m);
    fprintf(out, "Исходное среднее арифметическое: %.2f\n", sr1);
    fprintf(out, "==================================\n");

    int max_j = nom_max_otr_stolb(A, n, m);

    if (max_j == -1) {
        fprintf(out, "В матрице нет отрицательных элементов. Среднее арифметическое не изменится.\n");
    }
    else if (max_j == m - 1) {
        fprintf(out, "Столбец с макс. числом отрицательных элементов: %i (индекс %i) — последний.\n", max_j + 1, max_j);
        fprintf(out, "Столбцов с большими номерами нет. Среднее арифметическое не изменится.\n");
    }
    else {
        fprintf(out, "Столбец с макс. числом отрицательных элементов: %i (индекс %i)\n", max_j + 1, max_j);
        zamena_matr(A, n, m, max_j);

        fprintf(out, "Измененная матрица A:\n");
        Vivod(out, A, n, m);

        float sr2 = sr_arifm(A, n, m);
        float diff = sr2 - sr1;

        fprintf(out, "Новое среднее арифметическое: %.2f\n", sr2);
        if (diff > 0) {
            fprintf(out, "Среднее арифметическое увеличилось на %.2f\n", diff);
        } else {
            fprintf(out, "В столбцах правее нет отрицательных элементов. Среднее арифметическое не изменилось (0.00).\n");
        }
    }

    fclose(out);
    printf("Результат успешно записан в output.txt!\n");
    Ochistka(&A, n);

    return 0;
}
