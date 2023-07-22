#ifndef __CE_KEY_H__
#define __CE_KEY_H__

#include "ce_core.h"

#define KEYINT      0
#define KEYUINT     1
#define KEYSTR      2
typedef unsigned    ce_key_type_t;

typedef struct {
    union {
        int64_t     i;
        uint64_t    u;
        ce_str_t    s;
    } val;
    ce_key_type_t   typ:2;
} ce_key_t;

ce_key_t ce_key_int(int64_t i);
ce_key_t ce_key_uint(uint64_t u);
ce_key_t ce_key_str(ce_str_t *s);

// Compare ce_key_t
//  if k1.typ != k2.typ, return -2
//  if k1 > k2, return 1
//  if k1 == ke, return 0
//  if k1 < k2, return -1
int ce_key_cmp(ce_key_t k1, ce_key_t k2);

// return hash key for string, case sensitive
uint64_t ce_str_hash(char *str, size_t len);

// return hash key for string, case insensitive
uint64_t ce_strcase_hash(char *str, size_t len);

uint64_t ce_ptr_hash(void *ptr);

#endif
