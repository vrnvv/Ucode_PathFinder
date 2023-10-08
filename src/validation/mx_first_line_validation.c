#include "pathfinder.h"

void mx_first_line_validation(t_file *file) {
    int i = 0;
    
    if (file->spln_file[0][0] == '0' && file->spln_file[0][1] != '\0')
        mx_error_output(1, 3, 0, file);
    if (mx_atol(file->spln_file[0]) > INT_MAX)
        mx_error_output(1, 3, 0, file);
    while(file->spln_file[0][i]) {
        if (!mx_isdigit(file->spln_file[0][i]))
            mx_error_output(1, 3, 0, file);
        i++;
    }
}
