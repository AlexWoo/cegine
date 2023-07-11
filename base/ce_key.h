#ifndef __CE_KEY_H__
#define __CE_KEY_H__

#include "ce_core.h"

// return hash key for string, case sensitive
uint64_t ce_str_key(unsigned char *str, size_t len);

// return hash key for string, case insensitive
uint64_t ce_stccase_key(unsigned char *str, size_t len);

uint64_t ce_ptr_key(void *ptr);

#endif
