#include "ce_core.h"

ce_list_t   ce_event_queue;

void
ce_event_init() {
    ce_list_init(&ce_event_queue);
}

void
ce_post_event(ce_list_t *l, ce_event_t *ev) {
    if (!ev->posted) {
        ev->posted = 1;
        ce_list_push_tail(l, &ev->node);
    }
}

void
ce_delete_posted_event(ce_list_t *l, ce_event_t *ev) {
    if (ev->posted) {
        ev->posted = 0;
        ce_list_delete(l, &ev->node);
    }
}

void
ce_process_posted_event(ce_list_t *l) {
    ce_list_node_t     *node;
    ce_event_t         *ev;

    while (!ce_list_empty(l)) {
        node = ce_list_pop_head(l);
        ev = ce_entry(node, ce_event_t, node);

        ev->handler(ev);
    }
}
