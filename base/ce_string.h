#ifndef __CE_STRING_H__
#define __CE_STRING_H__

#include "ce_core.h"

typedef struct {
    char       *p;
    unsigned    len;
} ce_str_t;

#define ce_lowcase(c)                           \
    if (c >= 'A' && c <= 'Z') c |= 0x20

void ce_str_lowcase(ce_str_t *s);

// Compare s1 and s2 byte by byte
//  if s1 > s2 return 1
//  if s1 == s2 return 0
//  if s1 < s2 return -1
int ce_str_cmp(ce_str_t *s1, ce_str_t *s2);

// Compare s1 and s2 byte by byte, ignore case
//  if s1 > s2 return 1
//  if s1 == s2 return 0
//  if s1 < s2 return -1
int ce_strcase_cmp(ce_str_t *s1, ce_str_t *s2);

#endif
