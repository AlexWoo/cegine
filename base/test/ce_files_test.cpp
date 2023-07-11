#include "ce_core.h"
#include "ce_tester.h"

using namespace CETester;

CE_TESTCASE(CEFileOpen) {
    ce_file_t  *f;

    f = ce_file_open("test.txt", 2048*1024);
    EXPECT_EQ(f->bufsize, 2048*1024);
    EXPECT_EQ(f->p, f->buffer);
    ce_file_close(f);

    f = ce_file_open("test.txt", 1024);
    EXPECT_EQ(f->bufsize, 1024*1024);
    EXPECT_EQ(f->p, f->buffer);
    ce_file_close(f);

    // TODO file cannot open

    remove("test.txt");
}

CE_TESTCASE(CEWrite) {
    ce_file_t      *f;
    struct stat     st;

    f = ce_file_open("test.txt", 1024*1024);
    char *content = (char *)"0123456789";

    // Buffer not full, write buffer
    for (int i = 0; i < 104857; ++i) {
        ce_file_write(f, content, 10);
        EXPECT_EQ(f->p - f->buffer, (i + 1) * 10);
        fstat(f->fd, &st);
        EXPECT_EQ(st.st_size, 0);
    }

    // Buffer full, flush buffer
    ce_file_write(f, content, 10);
    EXPECT_EQ(f->p - f->buffer, 10);
    fstat(f->fd, &st);
    EXPECT_EQ(st.st_size, 1048570);

    ce_file_close(f);
    remove("test.txt");
}

CE_TESTCASE(CEFlush) {
    ce_file_t      *f;
    struct stat     st;

    f = ce_file_open("test.txt", 1024*1024);
    char *content = (char *)"0123456789";

    // Buffer not full, write buffer
    int i;
    for (i = 0; i < 10; ++i) {
        ce_file_write(f, content, 10);
    }
    EXPECT_EQ(f->p - f->buffer, i * 10);
    fstat(f->fd, &st);
    EXPECT_EQ(st.st_size, 0);

    // flush buffer
    ce_file_flush(f);
    EXPECT_EQ(f->p - f->buffer, 0);
    fstat(f->fd, &st);
    EXPECT_EQ(st.st_size, i * 10);

    ce_file_close(f);
    remove("test.txt");
}

CE_TESTCASE(CEClose) {
    ce_file_t      *f;
    struct stat     st;
    int             fd;

    f = ce_file_open("test.txt", 1024*1024);
    char *content = (char *)"0123456789";

    // Buffer not full, write buffer
    int i;
    for (i = 0; i < 10; ++i) {
        ce_file_write(f, content, 10);
    }
    EXPECT_EQ(f->p - f->buffer, i * 10);
    fstat(f->fd, &st);
    EXPECT_EQ(st.st_size, 0);

    ce_file_close(f);

    fd = open("test.txt", O_WRONLY, 0644);
    fstat(fd, &st);
    EXPECT_EQ(st.st_size, i * 10);
    close(fd);

    remove("test.txt");
}

CE_TESTCASE(CEReopen) {
    ce_file_t      *f;
    struct stat     st;
    int             fd;

    f = ce_file_open("test.txt", 2048*1024);
    char *content = (char *)"0123456789";

    // Buffer not full, write buffer
    int i;
    for (i = 0; i < 10; ++i) {
        ce_file_write(f, content, 10);
    }
    EXPECT_EQ(f->p - f->buffer, i * 10);
    fstat(f->fd, &st);
    EXPECT_EQ(st.st_size, 0);

    ce_file_reopen(f);

    EXPECT_EQ(f->bufsize, 2048*1024);
    EXPECT_EQ(f->p - f->buffer, 0);
    fstat(f->fd, &st);
    EXPECT_EQ(st.st_size, i * 10);

    ce_file_close(f);
    remove("test.txt");
}

int main() {
    RunAllTester();
}
