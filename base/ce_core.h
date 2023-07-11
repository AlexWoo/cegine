#ifndef __CE_CORE_H__
#define __CE_CORE_H__

#include "ce_linux_config.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "ce_key.h"
#include "ce_array.h"
#include "ce_list.h"
#include "ce_queue.h"
#include "ce_rbtree.h"
#include "ce_string.h"
#include "ce_time.h"
#include "ce_files.h"
#include "ce_log.h"

#define CE_VERSION 0.0.1

#define ce_entry(ptr, type, member)                 \
    (type*)((char*)ptr - offsetof(type, member))

#ifdef __cplusplus
}
#endif

#endif