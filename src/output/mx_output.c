#include "pathfinder.h"

static void print_distance(t_var *var, t_matrix *matrix) {
    int sum = 0;

    mx_printstr("Distance: ");
    for (int i = 1; i < matrix->m_len; i++){
        mx_printint(matrix->m_path[matrix->m_route[i]][matrix->m_route[i + 1]]);
        sum += matrix->m_path[matrix->m_route[i]][matrix->m_route[i + 1]];
        if (i < matrix->m_len - 1)
            mx_printstr(" + ");
        else if (i > 1) {
            mx_printstr(" = ");
            mx_printint(sum);
        }
    }
    mx_printstr("\n");
    mx_print_lines(0);
}

static void print_route(t_var *var, t_matrix *matrix) {
    mx_print_lines(0);
    mx_printstr("Path: ");
    mx_printstr(var->uniq_isl[matrix->m_route[1]]);
    mx_printstr(" -> ");
    mx_printstr(var->uniq_isl[matrix->m_route[matrix->m_len]]);
    mx_printstr("\n");
    mx_printstr("Route: ");
    for (int i = 1; i < matrix->m_len + 1; ) {
        mx_printstr(var->uniq_isl[matrix->m_route[i]]);
        ++i < matrix->m_len + 1 ? mx_printstr(" -> ") : mx_printstr("");
    }
    mx_printstr("\n");
}

static bool check_short_path(t_var *var, t_matrix *matrix, int k) {
    int i = matrix->m_route[matrix->m_len];
    int j = matrix->m_route[0];

    if (matrix->m_path[i][k] == matrix->m_sum[i][j] - matrix->m_sum[k][j] 
        && matrix->m_path[i][k] != INT_MAX && matrix->m_path[i][k] != 0)
        return true;
    return false;
}

static void short_part(t_var *var, t_matrix *matrix) {
    for (int k = 0; k < var->count_il; k++) {
        if (k != matrix->m_route[matrix->m_len]
            && check_short_path(var, matrix, k)) {
            matrix->m_route[++matrix->m_len] = k;
            short_part(var, matrix);
            matrix->m_len--;
        }
    }
    if (matrix->m_route[matrix->m_len] != matrix->m_route[0])
        return;
    print_route(var, matrix);
    print_distance(var, matrix);
}

void mx_output(t_var *var, t_matrix *matrix) {
    for (int i = 0; i < var->count_il; i++) {
        for (int j = i + 1; j < var->count_il; j++) {
            matrix->m_route = (int *)malloc(sizeof(int) * (var->count_il));
            matrix->m_len = 1;
            matrix->m_route[0] = j;
            matrix->m_route[matrix->m_len] = i;
            short_part(var, matrix);
            free(matrix->m_route);
        }
    }
}
