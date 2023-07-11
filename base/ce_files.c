#include "ce_core.h"

// Min buffer size: 1MB
#define MIN_BUFSIZE     1048576

ce_file_t *
ce_file_open(const char *path, size_t bufsize) {
    // TODO 文件是否已打开
    ce_file_t  *f;

    f = malloc(sizeof(ce_file_t));
    f->path = path;
    f->fd = open(f->path, O_CREAT|O_APPEND|O_WRONLY, 0644);
    if (f->fd < 0) {
        abort();
    }

    if (bufsize < MIN_BUFSIZE) {
        bufsize = MIN_BUFSIZE;
    }
    f->bufsize = bufsize;
    f->buffer = malloc(f->bufsize);
    f->p = f->buffer;

    return f;
}

void
ce_file_write(ce_file_t *f, const char *content, size_t size) {
    char       *last;

    // TODO 线程锁
    last = f->buffer + f->bufsize;
    if (last - f->p < size) {
        ce_file_flush(f);
    }

    memcpy(f->p, content, size);
    f->p += size;
}

void
ce_file_flush(ce_file_t *f) {
    // TODO 异常处理, file system is full
    write(f->fd, f->buffer, f->p - f->buffer);
    f->p = f->buffer;
}

void
ce_file_close(ce_file_t *f) {
    ce_file_flush(f);
    close(f->fd);
}

void
ce_file_reopen(ce_file_t *f) {
    ce_file_close(f);
    f->fd = open(f->path, O_CREAT|O_APPEND|O_WRONLY, 0644);
    if (f->fd < 0) {
        abort();
    }
}
