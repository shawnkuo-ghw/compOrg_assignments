#include "standard.h"


int max(const int a, const int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int maximum(const int size, int values[size]) {
    //TODO: complete
}

boolean is_even(const int value) {
    if (value & 1) {
        return FALSE;
    } else {
        return TRUE;
    }
}

boolean is_odd(const int value) {
    if (value & 1) {
        return TRUE;
    } else {
        return FALSE;
    }
}

boolean is_prime(const unsigned int value) {
    // TODO: done
    boolean isPrime = FALSE;
    if ( value == 2 ) {
        isPrime = TRUE;
    } else {
        int factor = 2;
        while ( !isPrime &&  factor < value ) {
            if ( value % factor == 0 ) {
                isPrime = FALSE;
            } else {
                factor ++;
            }
        }
    }
    return isPrime;
}

unsigned int fibonnaci(const unsigned int nth) {
    //TODO: complete
}