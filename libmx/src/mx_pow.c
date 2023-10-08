#include "libmx.h"

double mx_pow(double n, unsigned int pow) {
    double rp_n = 1;

        if (pow != 0) {
            while (pow != 0) {
                rp_n *= n;
                pow--;
            }
        }
        return rp_n;
}
