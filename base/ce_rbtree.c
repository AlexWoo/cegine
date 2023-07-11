#include "ce_core.h"

#define RED     0
#define BLK     1
#define DBLK    2

#define ce_rbtree_node_init(n)                  \
    (n)->p = NULL;                              \
    (n)->l = NULL;                              \
    (n)->r = NULL;                              \
    (n)->c = RED;

ce_rbtree_node_t*
ce_rbtree_get(ce_rbtree_t *rbt, uint64_t key) {
    return NULL;
}

void
ce_rbtree_insert(ce_rbtree_t *rbt, ce_rbtree_node_t *n) {
}

void
ce_rbtree_delete(ce_rbtree_t *rbt, uint64_t key) {
}