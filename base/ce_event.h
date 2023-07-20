#ifndef __CE_EVENT_H__
#define __CE_EVENT_H__

#include "ce_core.h"

typedef struct ce_event_s   ce_event_t;

typedef void (*ce_event_handler)(ce_event_t* ev);

struct ce_event_s {
    void               *data;
    ce_list_node_t      node;

    ce_event_handler    handler;

    unsigned            timeout:1;
    unsigned            posted:1;
    unsigned            closed:1;
};

extern ce_list_t    ce_event_queue;

void ce_event_init();

void ce_post_event(ce_list_t *l, ce_event_t *ev);

void ce_delete_posted_event(ce_list_t *l, ce_event_t *ev);

void ce_process_posted_event(ce_list_t *l);

#endif
