#include "pathfinder.h"

void mx_print_lines(int i) {
    if (i == 40) {
        mx_printchar('\n');
        return;
    }
    mx_printchar('=');
    ++i;
    mx_print_lines(i);
}
