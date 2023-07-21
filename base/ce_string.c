#include "ce_core.h"

void
ce_str_lowcase(ce_str_t *s) {
    for (int i = 0; i < s->len; ++i) {
        ce_lowcase(s->p[i]);
    }
}

int
ce_str_cmp(ce_str_t *s1, ce_str_t *s2) {
    unsigned len = ce_min(s1->len, s2->len);

    for (int i = 0; i < len; ++i) {
        if (s1->p[i] > s2->p[i]) return 1;
        if (s1->p[i] < s2->p[i]) return -1;
    }

    if (s1->len > s2->len) return 1;
    if (s1->len < s2->len) return -1;
    return 0;
}

int
ce_strcase_cmp(ce_str_t *s1, ce_str_t *s2) {
    char c1, c2;

    unsigned len = ce_min(s1->len, s2->len);

    for (int i = 0; i < len; ++i) {
        c1 = s1->p[i]; ce_lowcase(c1);
        c2 = s2->p[i]; ce_lowcase(c2);
        if (c1 > c2) return 1;
        if (c1 < c2) return -1;
    }

    if (s1->len > s2->len) return 1;
    if (s1->len < s2->len) return -1;
    return 0;
}
