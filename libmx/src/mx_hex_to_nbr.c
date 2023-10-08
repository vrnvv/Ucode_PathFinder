#include "libmx.h"

static unsigned long mx_counting(const char *hex) {
    unsigned long num = 0;
    unsigned long base = 1;

    for(int i = mx_strlen(hex) - 1; i >= 0; i--) {
        if (mx_isdigit(hex[i])) {
            num = num + (hex[i] - 48) * base;
            base *= 16;
        }
        if (mx_isalpha(hex[i])) {
            if (mx_islower(hex[i]) && hex[i] <= 'f') {
                num = num + (hex[i] - 87) * base;
                base *= 16;
            }
            else if (mx_isupper(hex[i]) && hex[i] <= 'F') {
                num = num + (hex[i] - 55) * base;
                base *= 16;
            }
        }
    }
    return num;
}

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long num = 0;

    if (!hex)
        return 0;
    else {
        num = mx_counting(hex);
        return num;
    }
}
