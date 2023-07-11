#ifndef __CE_QUEUE_H__
#define __CE_QUEUE_H__

#include "ce_core.h"

typedef struct ce_queue_node_s ce_queue_node_t;

struct ce_queue_node_s {
    ce_queue_node_t    *next;
};

typedef struct ce_queue_s {
    ce_queue_node_t    *head;
    ce_queue_node_t    *tail;
    uint32_t            size;
} ce_queue_t;

#define ce_queue_init(q)                        \
    (q)->head = NULL;                           \
    (q)->tail = NULL;                           \
    (q)->size = 0;

#define ce_queue_empty(q)                       \
    ((q)->size == 0)

#define ce_queue_size(q)                        \
    (q)->size

#define ce_queue_clear ce_queue_init

// put queue node into queue tail
void ce_queue_put(ce_queue_t *q, ce_queue_node_t *n);

// get queue node from queue head
ce_queue_node_t* ce_queue_get(ce_queue_t *q);

#endif
