#ifndef __CE_LIST_H__
#define __CE_LIST_H__

#include "ce_core.h"

typedef struct ce_list_node_s ce_list_node_t;

struct ce_list_node_s {
    ce_list_node_t *prev;
    ce_list_node_t *next;
};

typedef struct {
    ce_list_node_t  sentinel;
    uint32_t        size;
} ce_list_t;

#define ce_list_init(list)                      \
    (list)->sentinel.next = &(list)->sentinel;  \
    (list)->sentinel.prev = &(list)->sentinel;  \
    (list)->size = 0;

#define ce_list_empty(list)                     \
    ((list)->size = 0)

#define ce_list_size(list)                      \
    (list)->size

#define ce_list_clear ce_list_init

// insert newnode before node
#define ce_list_insert(list, node, newnode)     \
    (newnode)->next = node;                     \
    (newnode)->prev = (node)->prev;             \
    (node)->prev->next = newnode;               \
    (node)->prev = newnode;                     \
    ++(list)->size;

#define ce_list_delete(list, node)              \
    if (!ce_list_empty(list)) {                 \
        (node)->prev->next = (node)->next;      \
        (node)->next->prev = (node)->prev;      \
        --(list)->size;                         \
    }

#define ce_list_begin(list)                     \
    (list)->sentinel.next

#define ce_list_end(list)                       \
    &(list)->sentinel

void ce_list_push_head(ce_list_t *list, ce_list_node_t *node);
void ce_list_push_tail(ce_list_t *list, ce_list_node_t *node);

ce_list_node_t* ce_list_head(ce_list_t *list);
ce_list_node_t* ce_list_tail(ce_list_t *list);

ce_list_node_t* ce_list_pop_head(ce_list_t *list);
ce_list_node_t* ce_list_pop_tail(ce_list_t *list);

#endif
