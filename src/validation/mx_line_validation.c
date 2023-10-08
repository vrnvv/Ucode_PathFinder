#include "pathfinder.h"

static bool piped_line_split(t_file *file, int line) {
    int i = 0;
    int delim = 0;

    while (file->spln_file[line][i]) {
        if ((file->spln_file[line][i] == '-' && delim == 0) 
            && (mx_isalpha(file->spln_file[line][i - 1]))) {
            file->spln_file[line][i] = '|';
            delim++;
        }
        if ((file->spln_file[line][i] == ',' && delim == 1) 
            && (mx_isalpha(file->spln_file[line][i - 1]))) {
            file->spln_file[line][i] = '|';
            return true;
        }
        i++;
    }
    return false;
}

static bool line_valid_result(t_file *file, int line) {
    if ((mx_count_words(file->spln_file[line], '-') == 2) 
        && (mx_count_words(file->spln_file[line], ',') == 2))
        if (piped_line_split(file, line))
            if (mx_strlen(file->spln_file[line]) >= 5)
                if (mx_text_validation(file, line))
                    return true;
    mx_error_output(line + 1, 3, 0, file);
    return false;
}

void mx_line_validation(t_file *file, t_var *var) {
    int line = 0;

    while (file->spln_file[++line]) {
        line_valid_result(file, line);
    }
    blank_valid(file);
    if (file->spln_file[1])
        mx_islands_operates(file, var);
}
