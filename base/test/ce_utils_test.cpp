#include "ce_core.h"
#include "ce_tester.h"

using namespace CETester;

struct EntryTest {
    void       *p1;
    int         i2;
    float       f3;
    void       *p4;
};

CE_TESTCASE(Entry) {
    struct EntryTest e;

    void *p1 = &e.p1;
    void *p2 = &e.i2;
    void *p3 = &e.f3;
    void *p4 = &e.p4;

    TestPrint("e:%p p1:%p p2:%p p3:%p p4:%p", &e, p1, p2, p3, p4);

    EXPECT_EQ(ce_entry(p1, EntryTest, p1), &e);
    EXPECT_EQ(ce_entry(p2, EntryTest, i2), &e);
    EXPECT_EQ(ce_entry(p3, EntryTest, f3), &e);
    EXPECT_EQ(ce_entry(p4, EntryTest, p4), &e);
}

CE_TESTCASE(MaxAndMin) {
    int i1 = -100, i2 = 100;
    float f1 = 0.001, f2 = 0.0011;

    EXPECT_EQ(ce_min(i1, i2), i1);
    EXPECT_EQ(ce_max(i1, i2), i2);
    EXPECT_EQ(ce_min(f1, f2), f1);
    EXPECT_EQ(ce_max(f1, f2), f2);
}

int main() {
    RunAllTester();
}
