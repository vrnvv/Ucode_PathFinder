#include "libmx.h"

char *mx_concat_words(char **words) {
    char *str = NULL;
    char *tmp = NULL;

    if (!words)
        return NULL;

    for (int i = 0; words[i]; i++) {
        if (i == 0) {
           str = mx_strdup(words[i]);
        }
        else {
            tmp = mx_strjoin(str, " ");
            mx_strdel(&str);
            str = mx_strjoin(tmp, words[i]);
            mx_strdel(&tmp);
        }
    }
    return str;
}
