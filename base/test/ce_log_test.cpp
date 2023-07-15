#include "ce_core.h"
#include "ce_tester.h"

using namespace CETester;

CE_TESTCASE(LogTest) {
    ce_log_t   *log;
    size_t      len;

    ce_update_time();

    // para fix
    log = ce_log_create("test.log", 10, 5, 20);
    EXPECT_EQ(log->f->bufsize, 1024 * 1024);
    EXPECT_EQ(log->level, CE_LOG_INFO);
    EXPECT_EQ(log->output, CE_LOG_STD);
    ce_log_close(log);
    remove("test.log");

    // log to std
    log = ce_log_create("test.log", CE_LOG_INFO, CE_LOG_STD, 3*1024*1024);
    ce_log(log, CE_LOG_DEBUG, "log debug test %s %d %p", "hello", 1000, log);
    ce_log(log, CE_LOG_INFO,  "log info  test %s %d %p", "hello", 1000, log);
    ce_log(log, CE_LOG_ERROR, "log error test %s %d %p", "hello", 1000, log);
    ce_log(log, CE_LOG_FATAL, "log fatal test %s %d %p", "hello", 1000, log);
    ce_log_close(log);
    EXPECT_FILESIZE("test.log", 0);
    remove("test.log");

    // log to file
    log = ce_log_create("test.log", CE_LOG_INFO, CE_LOG_FILE, 3*1024*1024);
    ce_log(log, CE_LOG_DEBUG, "log debug test %s %d %p", "hello", 1000, log);
    ce_log(log, CE_LOG_INFO,  "log info  test %s %d %p", "hello", 1000, log);
    ce_log(log, CE_LOG_ERROR, "log error test %s %d %p", "hello", 1000, log);
    ce_log(log, CE_LOG_FATAL, "log fatal test %s %d %p", "hello", 1000, log);
    len = log->f->p - log->f->buffer;
    ce_log_close(log);
    EXPECT_FILESIZE("test.log", len + 3); // Windows 下转行会添加 /r
    remove("test.log");

    // log to file and std
    log = ce_log_create("test.log", CE_LOG_INFO, CE_LOG_FILE|CE_LOG_STD, 3*1024*1024);
    ce_log(log, CE_LOG_DEBUG, "log debug test %s %d %p", "hello", 1000, log);
    ce_log(log, CE_LOG_INFO,  "log info  test %s %d %p", "hello", 1000, log);
    ce_log(log, CE_LOG_ERROR, "log error test %s %d %p", "hello", 1000, log);
    ce_log(log, CE_LOG_FATAL, "log fatal test %s %d %p", "hello", 1000, log);
    len = log->f->p - log->f->buffer;
    ce_log_close(log);
    EXPECT_FILESIZE("test.log", len + 3); // Windows 下转行会添加 /r
    remove("test.log");
}

int main() {
    RunAllTester();
}
