#include "pathfinder.h"

int main(int argc, char *argv[]) {
    t_file *file = (t_file *)malloc(sizeof(t_file));
    t_var *var = (t_var *)malloc(sizeof(t_var));
    t_matrix *matrix = (t_matrix *)malloc(sizeof(t_matrix));
    
    mx_validation(argc, argv, file, var);
    if (file->spln_file[1]) {
        mx_matrix_init(file, var, matrix);
        mx_algorithm(var, matrix);
        mx_output(var, matrix);
        mx_matrix_clean(matrix, var);
    }
    mx_clean_memory_file(file);
    // system("leaks -q pathfinder");
    exit(1);
}
