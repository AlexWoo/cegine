#include "ce_core.h"

void
ce_list_push_head(ce_list_t *list, ce_list_node_t *node) {
    ce_list_insert(list, list->sentinel.next, node);
}

void
ce_list_push_tail(ce_list_t *list, ce_list_node_t *node) {
    ce_list_insert(list, &list->sentinel, node);
}

ce_list_node_t*
ce_list_head(ce_list_t *list) {
    if (ce_list_empty(list)) {
        return NULL;
    }
    return list->sentinel.next;
}

ce_list_node_t*
ce_list_tail(ce_list_t *list) {
    if (ce_list_empty(list)) {
        return NULL;
    }
    return list->sentinel.prev;
}

ce_list_node_t*
ce_list_pop_head(ce_list_t *list) {
    ce_list_node_t *head = ce_list_head(list);
    if (head != NULL) {
        ce_list_delete(list, head);
    }
    return head;
}

ce_list_node_t*
ce_list_pop_tail(ce_list_t *list) {
    ce_list_node_t *tail = ce_list_tail(list);
    if (tail != NULL) {
        ce_list_delete(list, tail);
    }
    return tail;
}
