#include "pathfinder.h"

void mx_var_clean(t_var *var) {
    if (var->temp_islands)
        mx_del_strarr(&var->temp_islands);
    if (var->digits)
        mx_del_strarr(&var->digits);
    if (var->uniq_isl)
        mx_del_strarr(&var->uniq_isl);
    free(var);
}
