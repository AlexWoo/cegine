#ifndef __CE_UTILS_H__
#define __CE_UTILS_H__

#define CE_VERSION 0.0.1

#define ce_entry(ptr, type, member)                 \
    (type*)((char*)ptr - offsetof(type, member))

#define ce_max(v1, v2) v1 > v2? v1: v2

#define ce_min(v1, v2) v1 < v2? v1: v2

#endif
