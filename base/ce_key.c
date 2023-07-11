#include "ce_core.h"

uint64_t
ce_str_key(unsigned char *str, size_t len) {
    uint64_t key = 0;

    for (size_t i =0; i < len; ++i) {
        key = key * 31 + str[i];
    }

    return key;
}

uint64_t
ce_stccase_key(unsigned char *str, size_t len) {
    uint64_t key = 0;

    for (int i = 0; i < len; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            key = key * 31 + (str[i] | 0x20); 
        } else {
            key = key * 31 + str[i];
        }
    }

    return key;
}

uint64_t
ce_ptr_key(void *ptr) {
    return (uint64_t)ptr;
}
