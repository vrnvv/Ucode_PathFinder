#pragma once

#include "libmx.h"

typedef struct s_file {
    char **spln_file;
    char *content;
}              t_file;

typedef struct s_var {
    char **temp_islands;
    char **uniq_isl;
    char **islands;
    char **digits;
    int count_il;
}              t_var;

typedef struct s_matrix
{
    long **m_path;
    long **m_sum;
    int *m_route;
    int m_len;
}              t_matrix;

void mx_error_output(int line, int flag, char *filename, t_file *file);
void mx_validation(int argc, char *argv[], t_file *file, t_var *var);
void mx_matrix_init(t_file *file, t_var *var, t_matrix *matrix);
void mx_file_validation(int argc, char *argv[], t_file *file);
void mx_output(t_var *var, t_matrix *matrix);
void mx_matrix_clean(t_matrix *matrix, t_var *var);
void mx_islands_operates(t_file *file, t_var *var);
void mx_line_validation(t_file *file, t_var *var);
bool mx_text_validation(t_file *file, int line);
void mx_algorithm(t_var *var, t_matrix *matrix);
void mx_null_valid(t_var *var, t_file *file);
void mx_output(t_var *var, t_matrix *matrix);
void mx_first_line_validation(t_file *file);
void mx_clean_memory_file(t_file *file);
void blank_valid(t_file *file);
void mx_var_clean(t_var *var);
void mx_print_lines(int i);
void mx_returner();
