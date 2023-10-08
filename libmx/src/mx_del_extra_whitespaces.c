#include "libmx.h"

char *mx_del_extra_whitespaces(const char *str, char dlm) {
    char *tmp = mx_strnew(mx_strlen(str) - 1);
    char *result;
    int flag = 0;
    int j = 0;

    for (int i = 0; i < mx_strlen(str) - 1; i++) {
        if (str[i] != dlm) {
            tmp[j] = str[i];
            j++;
            flag = 0;
        }
        else if (!flag) {
            tmp[j] = dlm;
            j++;
            flag = 1;
        }
    }
    result = mx_strtrim(tmp);
    mx_strdel(&tmp);
    return result;
}
