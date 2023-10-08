#include "pathfinder.h"

void mx_validation(int argc, char *argv[], t_file *file, t_var *var) {
    mx_file_validation(argc, argv, file);
    file->spln_file = mx_strsplit(file->content, '\n');
    mx_first_line_validation(file);
    mx_line_validation(file, var);
    mx_null_valid(var, file);
}
