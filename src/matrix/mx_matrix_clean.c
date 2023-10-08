#include "pathfinder.h"

void mx_matrix_clean(t_matrix *matrix, t_var *var) {
    if (matrix->m_path) {
        for (int i = 0; i < var->count_il; i++)
            free(matrix->m_path[i]);
        free(matrix->m_path);
    }
}
