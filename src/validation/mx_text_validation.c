#include "pathfinder.h"

static bool digit_valid(char *digit, int i) {
    while (digit[++i])
        if (!mx_isdigit(digit[i]))
            return false;
    return digit[i] == '\0' ? true : false;
}
static bool alpha_valid(char *iland, int i) {
    while (iland[++i])
        if (!mx_isalpha(iland[i]))
            return false;
    return iland[i] == '\0' ? true : false;
}
bool mx_text_validation(t_file *file, int line) {
    char **spl_str = mx_strsplit(file->spln_file[line], '|');
    if (spl_str)
        if (alpha_valid(spl_str[0], -1))
            if (alpha_valid(spl_str[1], -1))
                if (mx_strcmp(spl_str[0], spl_str[1]))
                    if (digit_valid(spl_str[2], -1)) {
                        mx_del_strarr(&spl_str);
                        return true;
                    }            
    mx_del_strarr(&spl_str);
    mx_error_output(line + 1, 3, 0, file);
    return false;
}
