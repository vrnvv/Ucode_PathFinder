#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *new = NULL;
    char *res = NULL;
    int j = 0;

    if (!str)
        return NULL;
    new = mx_strnew(mx_strlen(str));
    for (int i = 0; str[i] != '\0'; i++) {
        if (mx_isspace(str[i]) == 0) {
            new[j] = str[i];
            j++;
        }
        if (mx_isspace(str[i]) == 0 && mx_isspace(str[i + 1]) == 1) {
            new[j] = ' ';
            j++;
        }
    }
    res = mx_strtrim(new);
    mx_strdel(&new); 
    return res;
}
