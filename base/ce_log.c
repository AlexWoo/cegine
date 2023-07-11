#include "ce_core.h"

#define CE_MAX_LOG_STR  4096

const unsigned char* loglevel_str[CE_LOG_MAXLEVEL] = {
    "[Debug]",
    "[Info ]",
    "[Error]",
    "[Fatal]"
};

static int
ce_log_level_check(int level) {
    if (level > CE_LOG_FATAL || level < CE_LOG_DEBUG) {
        level = CE_LOG_INFO;
    }
}

ce_log_t *
ce_log_create(const char *path, int level, int output, size_t bufsize) {
    ce_log_t *log = malloc(sizeof(ce_log_t));

    log->f = ce_file_open(path, bufsize);
    if (log->f == NULL) {
        return NULL;
    }

    log->level = ce_log_level_check(level);
    log->output = output & (CE_LOG_STD|CE_LOG_FILE);

    return log;
}

void
ce_log_reopen(ce_log_t *log) {
    ce_file_reopen(log->f);
}

void
ce_log_flush(ce_log_t *log) {
    ce_file_flush(log->f);
}

void
ce_log_close(ce_log_t *log) {
    ce_file_close(log->f);
}

void
ce_log_core(ce_log_t *log, int level, const char *file, int line, const char *format, ...) {
    level = ce_log_level_check(level);
    if (level < log->level) {
        return;
    }

    va_list             args;
    unsigned char       tmp[CE_MAX_LOG_STR];
    unsigned char      *p, *last;

    p = tmp;
    last = tmp + CE_MAX_LOG_STR;

    // time
    memcpy(p, ce_log_time_str, sizeof(ce_log_time_str)); p += sizeof(ce_log_time_str);
    *p = ' '; ++p;

    // level
    memcpy(p, loglevel_str[level], sizeof("[Debug]")); p += sizeof("[Debug]");
    *p = ' '; ++p;

    // content
    va_start(args, format);
    p += snprintf(p, last - p, format, args);
    va_end(args);
    if (p == last) {
        printf("error log too long: %s\n", tmp);
        return;
    }
    *p = ' '; ++p;

    // location
    if (p == last) {
        printf("error log too long: %s\n", tmp);
        return;
    }
    p += snprintf(p, last - p, "[%s:%d]", file, line);
    if (p == last) {
        printf("error log too long: %s\n", tmp);
        return;
    }
    *p = '\n'; ++p;

    // log to file cache
    if (log->output & CE_LOG_FILE) {
        ce_file_write(log->f, tmp, p - tmp);
    }

    // log to console
    if (log->output & CE_LOG_STD) {
        write(STDOUT_FILENO, tmp, p - tmp);
    }
}
