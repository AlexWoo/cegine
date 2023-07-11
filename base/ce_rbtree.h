#ifndef __CE_RBTREE_H__
#define __CE_RBTREE_H__

typedef struct ce_rbtree_node_s ce_rbtree_node_t;

struct ce_rbtree_node_s {
    uint64_t            k;  // key
    ce_rbtree_node_t   *p;  // parent
    ce_rbtree_node_t   *l;  // left
    ce_rbtree_node_t   *r;  // right
    uint8_t             c;  // color
};

typedef struct {
    ce_rbtree_node_t   *root;
    ce_rbtree_node_t   *min;
    ce_rbtree_node_t   *max;
    uint32_t            size;
} ce_rbtree_t;

#define ce_rbtree_init(rbt)                     \
    (rbt)->root = NULL;                         \
    (rbt)->max = NULL;                          \
    (rbt)->min = NULL;                          \
    (rbt)->size = 0;

#define ce_rbtree_empty(rbt)                    \
    ((rbt)->root == NULL)

#define ce_rbtree_size(rbt)                     \
    (rbt)->size

#define ce_rbtree_min(rbt)                      \
    (rbt)->min

#define ce_rbtree_max(rbt)                      \
    (rbt)->max

ce_rbtree_node_t* ce_rbtree_get(ce_rbtree_t *rbt, uint64_t key);

void ce_rbtree_insert(ce_rbtree_t *rbt, ce_rbtree_node_t *n);

void ce_rbtree_delete(ce_rbtree_t *rbt, uint64_t key);


#endif
