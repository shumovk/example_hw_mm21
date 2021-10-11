#include "strutils.h"

size_t strlen(const char *str) {
    const char *i = str;

    while (*i != '\0') {
        i++;
    }
    return i - str;
}

size_t word_count(const char *str) {
    size_t count{0};
    bool flag;
    while (*str != '\0') {
        if (*str != ' ') {
            flag = true;
        } else {
            if (flag) {
                flag = false;
                count++;
            }
        }
        ++str;
    }
    if (flag) {
        count++;
    }
    return count;
}