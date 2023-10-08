#include "pathfinder.h"

static void memory_for_sum(t_var *var, t_matrix *matrix) {
    matrix->m_sum = (long **)malloc((sizeof(long *) * var->count_il));
    for (int y = 0; y < var->count_il; y++)
            matrix->m_sum[y] = (long *)malloc(sizeof(long) 
                                                    * var->count_il);
}

void mx_algorithm(t_var *var, t_matrix *matrix) {
    long sum;
    int i;

    memory_for_sum(var, matrix);
    for (i = 0; i < var->count_il; i++) {
        for (int j = i; j < var->count_il; j++) {
            matrix->m_sum[i][j] = matrix->m_path[i][j];
            matrix->m_sum[j][i] = matrix->m_path[j][i];
        }
    }
    for (int k = 0; k < var->count_il; k++) {
        for (i = 0; i < var->count_il; i++) {
            for (int j = i + 1; j < var->count_il; j++) {
                sum = matrix->m_sum[k][j] + matrix->m_sum[i][k];
                if (matrix->m_sum[i][j] > sum) {
                    matrix->m_sum[i][j] = sum;
                    matrix->m_sum[j][i] = sum;
                }
            }
        }
    }
}
