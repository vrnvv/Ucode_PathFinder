#include "pathfinder.h"

void mx_null_valid(t_var *var, t_file *file) {
    if (mx_atoi(file->spln_file[0]) > 0 && !file->spln_file[1])
        mx_error_output(0, 5, 0, file);
}
