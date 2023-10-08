#include "libmx.h"

int mx_arrlen(char **arrlen) {
    int arr_size = 0;

    while (arrlen[arr_size]) {
        arr_size++;   
    }
    return arr_size;
}
