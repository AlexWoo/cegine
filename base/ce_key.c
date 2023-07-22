#include "ce_core.h"

ce_key_t ce_key_int(int64_t i) {
    ce_key_t    k;
    k.val.i = i;
    k.typ = KEYINT;

    return k;
}

ce_key_t ce_key_uint(uint64_t u) {
    ce_key_t    k;
    k.val.u = u;
    k.typ = KEYUINT;

    return k;
}

ce_key_t ce_key_str(ce_str_t *s) {
    ce_key_t    k;
    k.val.s.p = s->p;
    k.val.s.len = s->len;
    k.typ = KEYSTR;

    return k;
}

int
ce_key_cmp(ce_key_t k1, ce_key_t k2) {
    if (k1.typ != k2.typ) {
        return -2;
    }

    if (k1.typ == KEYSTR) {
        return ce_str_cmp(&k1.val.s, &k2.val.s);
    }

    if (k1.typ == KEYINT) {
        if (k1.val.i < k2.val.i) {
            return -1;
        } else if (k1.val.i > k2.val.i) {
            return 1;
        } else {
            return 0;
        }
    }

    if (k1.typ == KEYUINT) {
        if (k1.val.u < k2.val.u) {
            return -1;
        } else if (k1.val.u > k2.val.u) {
            return 1;
        } else {
            return 0;
        }
    }
}

uint64_t
ce_str_hash(char *str, size_t len) {
    uint64_t key = 0;

    for (size_t i =0; i < len; ++i) {
        key = key * 31 + str[i];
    }

    return key;
}

uint64_t
ce_strcase_hash(char *str, size_t len) {
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
ce_ptr_hash(void *ptr) {
    return (uint64_t)ptr;
}
