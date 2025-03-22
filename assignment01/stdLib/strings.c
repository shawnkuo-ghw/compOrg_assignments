#include "standard.h"
#include <stdlib.h>
  
    //Return the length of the string
unsigned int length(const char * string) {

    unsigned int len = 0;
    while (string[len] != '\0') {  // until we meet '\0'
        len++;
    }
    return len;
}


    //Get string1 and string2,return if they are equeal
boolean equals(const char * string1, const char * string2) {
    
    unsigned int i = 0;
    while (string1[i] != '\0' && string2[i] != '\0') {  // keep compair，until '\0'
        if (string1[i] != string2[i]) 
            return FALSE;  // if some words not equal，return FALSE
        i++;
    }
    return string1[i] == string2[i];  // check if they are end at the same time
}



    //Find the index of position of e(first appear).
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

    //Find the index of position of e last appear
int last_index_of(const char * string, const char e) {
   
    int idx = -1;  // initial -1(not find)
    for (int i = 0; string[i] != '\0'; i++) {  // cover all the string
        if (string[i] == e) {
            idx = i;  // update index be the position of i word
        }
    }
    return idx;  // retrun the last appear  e's index，if not find then return -1
}



#define LOWER_CASE_MIN 97
#define LOWER_CASE_MAX 122

#define UPPER_CASE_MIN 65
#define UPPER_CASE_MAX 90

#define CASE_DIFF 32

// 'A' to 'a'
char * to_lower_case(const char * string) {
    unsigned int len = length(string);
    char * result = malloc(len + 1);  // allocate memory for the result string
    for (unsigned int i = 0; i < len; i++) {
        result[i] = shift_in_range(string[i], UPPER_CASE_MIN, UPPER_CASE_MAX, CASE_DIFF);  // 'A' to 'a'
    }
    result[len] = '\0';  // add the end '\0'
    return result;
}

// 'a' to 'A'
char * to_upper_case(const char * string) {
 
    unsigned int len = length(string);
    char * result = malloc(len + 1);  // allocate memory for the result string
    for (unsigned int i = 0; i < len; i++) {
        result[i] = shift_in_range(string[i], UPPER_CASE_MIN, UPPER_CASE_MAX, -CASE_DIFF);  // 'a' to 'A'
    }
    result[len] = '\0';  // 添加字符串结尾的 '\0'
    return result;
}
  

    //Switch the word
static char shift_in_range(const char c, unsigned int range_start, unsigned int range_end, const int shift) {
   
    if (c >= range_start && c <= range_end) {  // if the character is legal
        return c + shift;  // shift the word c,using the CASE_DIFF
    }
    return c;  // if the character is not within the range,return the original character directly
}

    
    //Return a substring 
char * substring(const char * string, unsigned int from, unsigned int to) {
    
    if (from >= to || from >= length(string)) {
        return NULL;  // if the index is wrong，return NULL
    }
    unsigned int len = to - from;
    char * result = malloc(len + 1);  // allocate memory for the substring
    for (unsigned int i = 0; i < len; i++) {
        result[i] = string[from + i];  // copy the substring
    }
    result[len] = '\0';  // add the '\0' to the end
    return result;
}

