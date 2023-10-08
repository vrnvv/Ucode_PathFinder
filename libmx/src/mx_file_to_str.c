#include "libmx.h"

char *mx_file_to_str(const char *file) {
    char *dst = NULL;
    int fd;
    int counter = 0;
    char ch;

    if (open(file, O_RDONLY) == -1) {
        return NULL;
    }
    fd = open(file, O_RDONLY);
    while (read(fd, &ch, 1))
        counter++;
    close(fd);
    fd = open(file, O_RDONLY);
    dst = mx_strnew(counter);
    for (int i = 0; read(fd, &ch, 1); i++)
        dst[i] = ch;
    close(fd);
    return dst;
}
