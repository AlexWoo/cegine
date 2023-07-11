#ifndef __CE_FILES_H__
#define __CE_FILES_H__

#include "ce_core.h"

typedef int ce_fd_t;

typedef struct {
    const char         *path;
    ce_fd_t             fd;

    char               *buffer;
    size_t              bufsize;
    char               *p;
} ce_file_t;

ce_file_t *ce_file_open(const char *path, size_t bufsize);

void ce_file_write(ce_file_t *f, const char *content, size_t size);

void ce_file_flush(ce_file_t *f);

void ce_file_close(ce_file_t *f);

void ce_file_reopen(ce_file_t *f);

#endif
