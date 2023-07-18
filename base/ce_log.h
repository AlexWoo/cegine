#ifndef __CE_LOG_H__
#define __CE_LOG_H__

#include "ce_core.h"

// Log Level
#define CE_LOG_DEBUG    0
#define CE_LOG_INFO     1
#define CE_LOG_ERROR    2
#define CE_LOG_FATAL    3
#define CE_LOG_MAXLEVEL 4

// Log Output
#define CE_LOG_STD      1
#define CE_LOG_FILE     2

typedef struct {
    ce_file_t      *f;
    int             level;
    int             output;
} ce_log_t;

ce_log_t *ce_log_create(const char *path, int level, int output, size_t bufsize);

void ce_log_reopen(ce_log_t *log);

void ce_log_flush(ce_log_t *log);

void ce_log_close(ce_log_t *log);

void ce_log_core(ce_log_t *log, int level, const char *file, int line, const char *format, ...);

#define ce_log(log, level, format, ...)         \
    ce_log_core(log, level, __FILE__, __LINE__, format, ##__VA_ARGS__)

#endif
