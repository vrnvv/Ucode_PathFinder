#include "pathfinder.h"

static int index_of_island(char *island, t_var *var) {
    for (int i = 0; var->uniq_isl[i]; i++)
        if (!mx_strcmp(island, var->uniq_isl[i]))
            return i;
    return 0;
}

static void matrix_dist_init(t_var *var, t_file *file, t_matrix *matrix) {
    int i;
    int j;
    int digit = 0;

    for (int x = 0; var->islands[x]; x += 2) {
        i = index_of_island(var->islands[x], var);
        j = index_of_island(var->islands[x + 1], var);
        matrix->m_path[i][j] = mx_atoi(var->digits[digit++]);
        matrix->m_path[j][i] = matrix->m_path[i][j];
    }
}

static void matrix_null_maxint(t_file *file, t_var *var, t_matrix *matrix) {
    for (int y = 0; y < var->count_il; y++) {
        for (int x = 0; x < var->count_il; x++) {
            matrix->m_path[y][x] = (y == x ? 0 : INT_MAX);
        }
    }
    matrix_dist_init(var, file, matrix);
}

void mx_matrix_init(t_file *file, t_var *var, t_matrix *matrix) {
    matrix->m_path = (long **)malloc((sizeof(long *) * var->count_il));
    for (int y = 0; y < var->count_il; y++) {
            matrix->m_path[y] = (long *)malloc(sizeof(long) 
                                                    * var->count_il);
    }
    matrix_null_maxint(file, var, matrix);
}
