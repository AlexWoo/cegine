#include "ce_core.h"
#include "ce_tester.h"

using namespace CETester;

CE_TESTCASE(ListBase) {
    ce_list_t       l;
    ce_list_node_t  n1, n2, n3, n4;

    ce_list_init(&l);
    EXPECT_EQ(l.sentinel.next, &l.sentinel);
    EXPECT_EQ(l.sentinel.prev, &l.sentinel);
    EXPECT_EQ(ce_list_empty(&l), 1);
    EXPECT_EQ(ce_list_size(&l), 0);

    ce_list_insert(&l, ce_list_begin(&l), &n1);
    EXPECT_EQ(ce_list_begin(&l), &n1);
    EXPECT_EQ(ce_list_end(&l), &l.sentinel);
    EXPECT_EQ(l.sentinel.next, &n1);
    EXPECT_EQ(n1.next, &l.sentinel);
    EXPECT_EQ(l.sentinel.prev, &n1);
    EXPECT_EQ(n1.prev, &l.sentinel);
    EXPECT_EQ(ce_list_empty(&l), 0);
    EXPECT_EQ(ce_list_size(&l), 1);

    ce_list_insert(&l, ce_list_end(&l), &n2);
    EXPECT_EQ(ce_list_begin(&l), &n1);
    EXPECT_EQ(l.sentinel.next, &n1);
    EXPECT_EQ(n1.next, &n2);
    EXPECT_EQ(n2.next, &l.sentinel);
    EXPECT_EQ(l.sentinel.prev, &n2);
    EXPECT_EQ(n2.prev, &n1);
    EXPECT_EQ(n1.prev, &l.sentinel);
    EXPECT_EQ(ce_list_empty(&l), 0);
    EXPECT_EQ(ce_list_size(&l), 2);

    ce_list_insert(&l, ce_list_begin(&l), &n3)
    EXPECT_EQ(ce_list_begin(&l), &n3);
    EXPECT_EQ(l.sentinel.next, &n3);
    EXPECT_EQ(n3.next, &n1);
    EXPECT_EQ(n1.next, &n2);
    EXPECT_EQ(n2.next, &l.sentinel);
    EXPECT_EQ(l.sentinel.prev, &n2);
    EXPECT_EQ(n2.prev, &n1);
    EXPECT_EQ(n1.prev, &n3);
    EXPECT_EQ(n3.prev, &l.sentinel);
    EXPECT_EQ(ce_list_empty(&l), 0);
    EXPECT_EQ(ce_list_size(&l), 3);

    ce_list_insert(&l, &n1, &n4)
    EXPECT_EQ(ce_list_begin(&l), &n3);
    EXPECT_EQ(l.sentinel.next, &n3);
    EXPECT_EQ(n3.next, &n4);
    EXPECT_EQ(n4.next, &n1);
    EXPECT_EQ(n1.next, &n2);
    EXPECT_EQ(n2.next, &l.sentinel);
    EXPECT_EQ(l.sentinel.prev, &n2);
    EXPECT_EQ(n2.prev, &n1);
    EXPECT_EQ(n1.prev, &n4);
    EXPECT_EQ(n4.prev, &n3);
    EXPECT_EQ(n3.prev, &l.sentinel);
    EXPECT_EQ(ce_list_empty(&l), 0);
    EXPECT_EQ(ce_list_size(&l), 4);

    ce_list_delete(&l, &n4);
    EXPECT_EQ(ce_list_begin(&l), &n3);
    EXPECT_EQ(l.sentinel.next, &n3);
    EXPECT_EQ(n3.next, &n1);
    EXPECT_EQ(n1.next, &n2);
    EXPECT_EQ(n2.next, &l.sentinel);
    EXPECT_EQ(l.sentinel.prev, &n2);
    EXPECT_EQ(n2.prev, &n1);
    EXPECT_EQ(n1.prev, &n3);
    EXPECT_EQ(n3.prev, &l.sentinel);
    EXPECT_EQ(ce_list_empty(&l), 0);
    EXPECT_EQ(ce_list_size(&l), 3);

    ce_list_clear(&l);
    EXPECT_EQ(l.sentinel.next, &l.sentinel);
    EXPECT_EQ(l.sentinel.prev, &l.sentinel);
    EXPECT_EQ(ce_list_empty(&l), 1);
    EXPECT_EQ(ce_list_size(&l), 0);
}

CE_TESTCASE(ListPushAndPop) {
    ce_list_t       l;
    ce_list_node_t  n1, n2, n3, n4;

    ce_list_init(&l);
    ce_list_push_head(&l, &n1);
    EXPECT_EQ(ce_list_head(&l), &n1);
    EXPECT_EQ(ce_list_tail(&l), &n1);
    EXPECT_EQ(ce_list_size(&l), 1);

    ce_list_push_head(&l, &n2);
    EXPECT_EQ(ce_list_head(&l), &n2);
    EXPECT_EQ(ce_list_tail(&l), &n1);
    EXPECT_EQ(ce_list_size(&l), 2);

    ce_list_push_tail(&l, &n3);
    ce_list_push_tail(&l, &n4);
    EXPECT_EQ(ce_list_head(&l), &n2);
    EXPECT_EQ(ce_list_tail(&l), &n4);
    EXPECT_EQ(ce_list_size(&l), 4);

    ce_list_node_t *n = ce_list_pop_tail(&l);
    EXPECT_EQ(n, &n4);
    EXPECT_EQ(ce_list_head(&l), &n2);
    EXPECT_EQ(ce_list_tail(&l), &n3);
    EXPECT_EQ(ce_list_size(&l), 3);

    n = ce_list_pop_head(&l);
    EXPECT_EQ(n, &n2);
    EXPECT_EQ(ce_list_head(&l), &n1);
    EXPECT_EQ(ce_list_tail(&l), &n3);
    EXPECT_EQ(ce_list_size(&l), 2);

    ce_list_pop_head(&l);
    ce_list_pop_tail(&l);
    EXPECT_EQ(l.sentinel.next, &l.sentinel);
    EXPECT_EQ(l.sentinel.prev, &l.sentinel);
    EXPECT_EQ(ce_list_empty(&l), 1);
    EXPECT_EQ(ce_list_size(&l), 0);

    n = ce_list_pop_head(&l);
    EXPECT_EQ(n, NULL);
    EXPECT_EQ(l.sentinel.next, &l.sentinel);
    EXPECT_EQ(l.sentinel.prev, &l.sentinel);
    EXPECT_EQ(ce_list_empty(&l), 1);
    EXPECT_EQ(ce_list_size(&l), 0);

    n = ce_list_pop_tail(&l);
    EXPECT_EQ(n, NULL);
    EXPECT_EQ(l.sentinel.next, &l.sentinel);
    EXPECT_EQ(l.sentinel.prev, &l.sentinel);
    EXPECT_EQ(ce_list_empty(&l), 1);
    EXPECT_EQ(ce_list_size(&l), 0);
}

int main() {
    RunAllTester();
}
