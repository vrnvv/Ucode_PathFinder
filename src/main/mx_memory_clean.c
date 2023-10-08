#include "pathfinder.h"

void mx_clean_memory_file(t_file *file) {
    if (file->content)
        mx_strdel(&file->content);
    if (file->spln_file)
        mx_del_strarr(&file->spln_file);
    free(file);
}
