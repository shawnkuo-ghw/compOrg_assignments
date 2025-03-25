#include "standard.h"
#include <stdlib.h>
  
static char shift_in_range(const char c, unsigned int range_start, unsigned int range_end, const int shift);


unsigned int length(const char * string) {
    // DONE by lms
    unsigned int len = 0;
    while (string[len] != '\0') {
        len++;
    }
    return len;
}


boolean equals(const char * string1, const char * string2) {
    // DONE by ghw
    boolean is_equal = TRUE;
    if ( string1 != string2 ) {
        unsigned int len1 = length(string1);
        unsigned int len2 = length(string2);
        if ( len1 != len2 ) {
            is_equal = FALSE;
        } else {
            unsigned int i = 0;
            while ( is_equal && i < len1 ) {
                if ( string1[i] != string2[i] ) {
                    is_equal = FALSE;
                } else {
                    i ++;
                }
            }
        }
    }
    return is_equal;
}


int index_of(const char * string, const char e) {
    int idx = 0;
    boolean found = FALSE;
    while (string[idx] != 0) {
        if (string[idx] == e) {
            return idx;
        }
        idx++;
    }
    return found?idx:-1;
}


int last_index_of(const char * string, const char e) {
    // DONE by lms
    int idx = -1;  
    for (int i = 0; string[i] != '\0'; i++) {  
        if (string[i] == e) {
            idx = i;  
        }
    }
    return idx;  
}



#define LOWER_CASE_MIN 97
#define LOWER_CASE_MAX 122

#define UPPER_CASE_MIN 65
#define UPPER_CASE_MAX 90

#define CASE_DIFF 32


char * to_lower_case(const char * string) {
    // DONE by lms
    unsigned int len = length(string);
    char * result = malloc(len + 1);  
    for (unsigned int i = 0; i < len; i++) {
        result[i] = shift_in_range(string[i], UPPER_CASE_MIN, UPPER_CASE_MAX, CASE_DIFF);  
    }
    result[len] = '\0';  
    return result;
}


char * to_upper_case(const char * string) {
    // DONE by lms
    unsigned int len = length(string);
    char * result = malloc(len + 1);  
    for (unsigned int i = 0; i < len; i++) {
        result[i] = shift_in_range(string[i], UPPER_CASE_MIN, UPPER_CASE_MAX, -CASE_DIFF);  
    }
    result[len] = '\0';  
    return result;
}
  

    
static char shift_in_range(const char c, unsigned int range_start, unsigned int range_end, const int shift) {
    // DONE by lms
    if (c >= range_start && c <= range_end) {  
        return c + shift;  
    }
    return c;  
}
   

char * substring(const char * string, unsigned int from, unsigned int to) {
    // DONE by lms
    if (from >= to || from >= length(string)) {
        return NULL;  
    }
    unsigned int len = to - from;
    char * result = malloc(len + 1);  
    for (unsigned int i = 0; i < len; i++) {
        result[i] = string[from + i];  
    }
    result[len] = '\0';  
    return result;
}