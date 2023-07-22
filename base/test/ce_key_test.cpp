#include "ce_core.h"
#include "ce_tester.h"

using namespace CETester;

CE_TESTCASE(Key) {
    ce_key_t ki1 = ce_key_int(-10);
    ce_key_t ki2 = ce_key_int(-1);
    ce_key_t ki3 = ce_key_int(10);

    EXPECT_EQ(ce_key_cmp(ki1, ki1), 0);
    EXPECT_EQ(ce_key_cmp(ki1, ki2), -1);
    EXPECT_EQ(ce_key_cmp(ki3, ki1), 1);

    ce_key_t ku1 = ce_key_uint(0);
    ce_key_t ku2 = ce_key_uint(0xffffffffffffffff);
    ce_key_t ku3 = ce_key_uint(10);

    EXPECT_EQ(ce_key_cmp(ku1, ku1), 0);
    EXPECT_EQ(ce_key_cmp(ku1, ku2), -1);
    EXPECT_EQ(ce_key_cmp(ku2, ku3), 1);

    char s1[] = "Hello World";
    char s2[] = "hello world";
    char s3[] = "Hello World1";
    ce_str_t str1; str1.p = s1; str1.len = strlen(s1);
    ce_str_t str2; str2.p = s2; str2.len = strlen(s2);
    ce_str_t str3; str3.p = s3; str3.len = strlen(s3);
    ce_key_t ks1 = ce_key_str(&str1);
    ce_key_t ks2 = ce_key_str(&str2);
    ce_key_t ks3 = ce_key_str(&str3);

    EXPECT_EQ(ce_key_cmp(ks1, ks1), 0);
    EXPECT_EQ(ce_key_cmp(ks1, ks2), -1);
    EXPECT_EQ(ce_key_cmp(ks3, ks1), 1);

    EXPECT_EQ(ce_key_cmp(ki1, ku1), -2);
    EXPECT_EQ(ce_key_cmp(ks1, ku1), -2);
    EXPECT_EQ(ce_key_cmp(ki1, ks1), -2);
}

CE_TESTCASE(Hash) {
    char s1[] = "Hello World";
    char s2[] = "hello world";
    char s3[] = "Hello World1";

    TestPrint("%d %d %d    %d %d %d   %d(%p) %d(%p) %d(%p)",
        ce_str_hash(s1, strlen(s1)),
        ce_str_hash(s2, strlen(s2)),
        ce_str_hash(s3, strlen(s3)),
        ce_strcase_hash(s1, strlen(s1)),
        ce_strcase_hash(s2, strlen(s2)),
        ce_strcase_hash(s3, strlen(s3)),
        ce_ptr_hash(s1), s1,
        ce_ptr_hash(s2), s2,
        ce_ptr_hash(s3), s3);
    
    EXPECT_NE(ce_str_hash(s1, strlen(s1)), ce_str_hash(s2, strlen(s2)));
    EXPECT_EQ(ce_strcase_hash(s1, strlen(s1)), ce_strcase_hash(s2, strlen(s2)));
    EXPECT_NE(ce_ptr_hash(s1), ce_ptr_hash(s2));
    EXPECT_EQ(ce_ptr_hash(s1), ce_ptr_hash(s1));
}

int main() {
    RunAllTester();
}
