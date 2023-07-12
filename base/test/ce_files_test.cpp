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

    f = ce_file_open("test.txt", 1024*1024);
    char *content = (char *)"0123456789";

    // Buffer not full, write buffer
    for (int i = 0; i < 104857; ++i) {
        ce_file_write(f, content, 10);
        EXPECT_EQ(f->p - f->buffer, (i + 1) * 10);
        EXPECT_FILESIZE_FD(f->fd, 0);
    }

    // Buffer full, flush buffer
    ce_file_write(f, content, 10);
    EXPECT_EQ(f->p - f->buffer, 10);
    EXPECT_FILESIZE_FD(f->fd, 1048570);

    ce_file_close(f);
    remove("test.txt");
}

CE_TESTCASE(CEFlush) {
    ce_file_t      *f;

    f = ce_file_open("test.txt", 1024*1024);
    char *content = (char *)"0123456789";

    // Buffer not full, write buffer
    int i;
    for (i = 0; i < 10; ++i) {
        ce_file_write(f, content, 10);
    }
    EXPECT_EQ(f->p - f->buffer, i * 10);
    EXPECT_FILESIZE_FD(f->fd, 0);

    // flush buffer
    ce_file_flush(f);
    EXPECT_EQ(f->p - f->buffer, 0);
    EXPECT_FILESIZE_FD(f->fd, i * 10);

    ce_file_close(f);
    remove("test.txt");
}

CE_TESTCASE(CEClose) {
    ce_file_t      *f;

    f = ce_file_open("test.txt", 1024*1024);
    char *content = (char *)"0123456789";

    // Buffer not full, write buffer
    int i;
    for (i = 0; i < 10; ++i) {
        ce_file_write(f, content, 10);
    }
    EXPECT_EQ(f->p - f->buffer, i * 10);
    EXPECT_FILESIZE_FD(f->fd, 0);

    ce_file_close(f);

    EXPECT_FILESIZE("test.txt", i * 10);

    remove("test.txt");
}

CE_TESTCASE(CEReopen) {
    ce_file_t      *f;

    f = ce_file_open("test.txt", 2048*1024);
    char *content = (char *)"0123456789";

    // Buffer not full, write buffer
    int i;
    for (i = 0; i < 10; ++i) {
        ce_file_write(f, content, 10);
    }
    EXPECT_EQ(f->p - f->buffer, i * 10);
    EXPECT_FILESIZE_FD(f->fd, 0);

    ce_file_reopen(f);

    EXPECT_EQ(f->bufsize, 2048*1024);
    EXPECT_EQ(f->p - f->buffer, 0);
    EXPECT_FILESIZE_FD(f->fd, i * 10);

    ce_file_close(f);
    remove("test.txt");
}

int main() {
    RunAllTester();
}
