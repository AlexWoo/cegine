#include "ce_core.h"
#include "ce_tester.h"

using namespace CETester;

CE_TESTCASE(LowCase) {
    char c1 = ' ', c2 = 'A', c3 = 'z';

    ce_lowcase(c1);
    ce_lowcase(c2);
    ce_lowcase(c3);
    EXPECT_EQ(c1, ' ');
    EXPECT_EQ(c2, 'a');
    EXPECT_EQ(c3, 'z');

    char s[] = "Hello World, CEngine!";
    ce_str_t str;
    str.p = s;
    str.len = strlen(s);
    ce_str_lowcase(&str);

    EXPECT_CSTR_EQ(s, "hello world, cengine!");
}

CE_TESTCASE(StrCmp) {
    char s1[] = "ABCddef";
    char s2[] = "ABCddef1";
    char s3[] = "abcDDef";
    char s4[] = "ABDddef";
    char s5[] = "abbddef2345";

    ce_str_t str1, str2, str3, str4, str5;
    str1.p = s1; str1.len = strlen(s1);
    str2.p = s2; str2.len = strlen(s2);
    str3.p = s3; str3.len = strlen(s3);
    str4.p = s4; str4.len = strlen(s4);
    str5.p = s5; str5.len = strlen(s5);

    EXPECT_EQ(ce_str_cmp(&str1, &str2), -1);
    EXPECT_EQ(ce_str_cmp(&str4, &str1), 1);
    EXPECT_EQ(ce_str_cmp(&str3, &str5), 1);
    EXPECT_EQ(ce_str_cmp(&str1, &str1), 0);
    EXPECT_EQ(ce_strcase_cmp(&str1, &str3), 0);
    EXPECT_EQ(ce_strcase_cmp(&str1, &str5), 1);
    EXPECT_EQ(ce_strcase_cmp(&str3, &str2), -1);
}

int main() {
    RunAllTester();
}
