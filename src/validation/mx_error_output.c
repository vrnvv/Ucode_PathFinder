#include "pathfinder.h"
static void usage_file(int flag, char *filename) {
    flag == 0 ? mx_printerr("usage: ./pathfinder [filename]\n"), 
                exit(2) : mx_returner();
    flag == 1 ? mx_printerr("error: file "), mx_printerr(filename),
                mx_printerr(" does not exist\n"),
                exit(2) : mx_returner();
    flag == 2 ? mx_printerr("error: file "), mx_printerr(filename),
                mx_printerr(" is empty\n"),
                exit(2) : mx_returner();
}
static void line_invalid(int line, int flag) {
    flag == 3 ? mx_printerr("error: line "), mx_printerr(mx_itoa(line)),
                mx_printerr(" is not valid\n"),
                exit(2) : mx_returner();
    flag == 4 ? mx_printerr("error: duplicate bridges\n"),
                exit(2) : mx_returner();
    flag == 5 ? mx_printerr("error: invalid number of islands\n"),
                exit(2) : mx_returner();
    flag == 6 ? mx_printerr("error: sum of bridges lengths is too big\n"),
                exit(2) : mx_returner();
}
void mx_error_output(int line, int flag, char *filename, t_file *file) {
    // system("leaks -q pathfinder");
    flag <= 2 ? usage_file(flag, filename) : mx_returner();
    flag >= 3 ? line_invalid(line, flag) : mx_returner();
}
