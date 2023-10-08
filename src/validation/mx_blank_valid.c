#include "pathfinder.h"

void blank_valid(t_file *file) {
    int line = 0;

    for (int i = 0; file->content[i]; i++) {
        if (file->content[0] == '\0' || file->content[0] == '\n')
            mx_error_output(line + 1, 3, 0, file);
        if (file->content[i] == '\n')
            line++;
        if (file->content[i + 1] == '\0' && file->content[i] != '\n')
            mx_error_output(line + 1, 3, 0, file);
        if ((file->content[i + 1] && file->content[i] == '\n') 
            && (file->content[i + 1] == '\n'))
            mx_error_output(line + 1, 3, 0, file);
    }
}
