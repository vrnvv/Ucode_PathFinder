#include "pathfinder.h"

void mx_file_validation(int argc, char *argv[], t_file *file) {
    file->content = mx_file_to_str(argv[1]);
    if (argc != 2)
        mx_error_output(0, 0, 0, file);
    if (!file->content)
        mx_error_output(0, 1, argv[1], file);
    if (file->content && file->content[0] == '\0')
        mx_error_output(0, 2, argv[1], file);
}
