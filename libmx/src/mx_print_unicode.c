#include "libmx.h"

static void two_multichar(wchar_t c) {
   char arr[3] = {0};

    arr[0] = (c >> 6 & 31) | 192;
    arr[1] = (c & 63) | 128;
    mx_printstr(arr);
}

static void three_multichar(wchar_t c) {
    char arr[4] = {0};

    arr[0] = (c >> 12 & 15) | 224;
    arr[1] = (c >> 6 & 63) | 128;
    arr[2] = (c >> 0 & 63) | 128;
    mx_printstr(arr);
}

static void four_multichar(wchar_t c) {
    char arr[5] = {0};

    arr[0] = (c >> 18 & 7) | 240;
    arr[1] = (c >> 12 & 63) | 128;
    arr[2] = (c >> 6 & 63) | 128;
    arr[3] = (c >> 0 & 63) | 128;
    mx_printstr(arr);
}

void mx_print_unicode(wchar_t c) {
    if (c <= 127)
        mx_printchar(c);
    else if (c <= 2048)
        two_multichar(c);
    else if (c <= 65536)
        three_multichar(c);
    else 
        four_multichar(c);
}

// 010000 >> 6 >> 000001 & 011111 = 011111 | (0000001) -> 0000001 0100000
// 010000
// 100000
// 110000
// 111000
