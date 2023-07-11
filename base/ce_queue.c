#include "ce_core.h"

void
ce_queue_put(ce_queue_t *q, ce_queue_node_t *n) {
    if (q->size == 0) {
        q->head = q->tail = n;
    } else {
        q->tail->next = n;
        q->tail = n;
    }

    n->next = NULL;

    ++q->size;
}

ce_queue_node_t*
ce_queue_get(ce_queue_t *q) {
    ce_queue_node_t    *n;

    // if head is NULL, return NULL
    if (q->head == NULL) {
        return NULL;
    }

    n = q->head;
    q->head = q->head->next;

    // queue is empty now
    if (q->head == NULL) {
        q->tail = q->head;
    }

    --q->size;

    return n;
}
