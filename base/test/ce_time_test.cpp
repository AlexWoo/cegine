#include "ce_core.h"
#include "ce_tester.h"

using namespace CETester;

CE_TESTCASE(TimeTest) {
    unsigned char tmp[sizeof(ce_log_time_str)];

    ce_update_time();
    memcpy(tmp, ce_log_time_str, sizeof(ce_log_time_str));

    usleep(10000);
    EXPECT_CSTR_EQ(tmp, ce_log_time_str);

    ce_update_time();
    EXPECT_CSTR_NE(tmp, ce_log_time_str);

    TestPrint("%s", tmp);
}

int main() {
    RunAllTester();
}
