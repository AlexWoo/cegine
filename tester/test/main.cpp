#include "ce_tester.h"

using namespace CETester;

CE_TESTCASE(Print) {
    TestPrint("Print");
    TestPrint("Hello %s %d", "World", 1000);
}

CE_TESTCASE(TestEQNE) {
    int i = 10, j = 20;

    EXPECT_EQ(1, 1);
    EXPECT_EQ(20, 20.0);
    EXPECT_EQ("Hello", "Hello");

    EXPECT_NE("Hello", "World");
    EXPECT_NE(i, j);
}

CE_TESTCASE(TestSTREQNE) {
    char *s1  = (char *)"Hello";
    char s2[] = "Hello";
    char *s3  = (char*)"World";

    EXPECT_NE(s1, s2);
    EXPECT_CSTR_EQ(s1, s2);
    EXPECT_CSTR_NE(s1, s3);
    EXPECT_CSTR_NE(s2, s3);
}

CE_TESTCASE(TestFile) {
    char *path = (char *)"test.txt";
    int fd = open(path, O_CREAT|O_APPEND|O_WRONLY, 0644);
    EXPECT_FILESIZE(path, 0);
    EXPECT_FILESIZE_FD(fd, 0);

    write(fd, "0123456789", 10);
    EXPECT_FILESIZE(path, 10);
    EXPECT_FILESIZE_FD(fd, 10);
    close(fd);

    remove(path);
}

int main() {
    RunAllTester();
}
