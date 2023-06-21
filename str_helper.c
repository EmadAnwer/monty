#include "monty.h"

int is_number(const char *str) {
    if (str == NULL || *str == '\0') {
        return 0;  // Empty string
    }

    // Check for optional sign (+ or -)
    if (*str == '-' || *str == '+') {
        ++str;  // Skip the sign character
    }

    // Check for digits
    int has_digits = 0;
    while (*str != '\0') {
        if (*str < '0' || *str > '9') {
            return 0;  // Non-digit character found
        }
        has_digits = 1;
        ++str;
    }

    return (has_digits) ? -1 : 0;
}
