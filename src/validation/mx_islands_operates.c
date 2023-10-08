#include "pathfinder.h"

static void sumbridges_ilcount(t_file *file, t_var *var) {
    int i = -1;
    long long sum = 0;

    if (var->count_il != mx_arrlen(var->uniq_isl))
        mx_error_output(0, 5, 0, file);
    while (var->digits[++i] != NULL) {
        sum += mx_atol(var->digits[i]);
    }
    if (sum > INT_MAX)
        mx_error_output(0, 6, 0, file);
}

static void indub_valid(t_file *file, t_var *var) {
    for (int i = 0; i < mx_arrlen(var->islands) - 1; i += 2) {
        for (int j = i + 2; j < mx_arrlen(var->islands) - 1; j += 2) {
            if (!mx_strcmp(var->islands[i], var->islands[j])
                || !mx_strcmp(var->islands[i], var->islands[j + 1])) {
                if (!mx_strcmp(var->islands[i + 1], var->islands[j + 1])
                    || !mx_strcmp(var->islands[i + 1], var->islands[j])) {
                        mx_error_output(0, 4, 0, file);
                }
            }
        }
    }
}

static void uniq_islands(t_file *file, t_var *var) {
    var->count_il = mx_atoi(file->spln_file[0]);
    var->uniq_isl = (char **)malloc(sizeof(char *) * var->count_il * 8);
    bool flag = true;
    int j;

    for (int i = 0; i < var->count_il; i++)
        var->uniq_isl[i] = NULL;
    for (int i = 0; var->islands[i] != NULL; i++) {
        flag = true;
        for (j = 0; var->uniq_isl[j] != NULL && j < var->count_il; j++)
            if (mx_strcmp(var->islands[i], var->uniq_isl[j]) == 0)
                flag = false;
        if (flag)
            var->uniq_isl[j] = mx_strdup(var->islands[i]);
    }
}

static void islands_write(t_file *file, t_var *var) {
    var->islands = (char **)malloc(sizeof(char *)
                                   * mx_arrlen(file->spln_file) * 8);
    var->temp_islands = (char **)malloc(sizeof(char *) 
                                   * mx_arrlen(file->spln_file) * 8);
    var->digits = (char **)malloc(sizeof(char *) 
                                   * mx_arrlen(file->spln_file) * 8);
    char **temp = NULL;
    int i = 0;
    int pos = -1;
    int posd = -1;

    while (file->spln_file[++i]) {
        temp = mx_strsplit(file->spln_file[i], '|');
        var->islands[++pos] = mx_strdup(temp[0]);
        var->temp_islands[pos] = mx_strdup(temp[0]);
        var->islands[++pos] = mx_strdup(temp[1]);
        var->temp_islands[pos] = mx_strdup(temp[1]);
        var->digits[++posd] = mx_strdup(temp[2]);
        mx_del_strarr(&temp);
    }
}

void mx_islands_operates(t_file *file, t_var *var) {
    islands_write(file, var);
    uniq_islands(file, var);
    sumbridges_ilcount(file, var);
    indub_valid(file, var);
}
