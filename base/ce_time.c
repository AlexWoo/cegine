#include "ce_core.h"

void ce_update_time() {
    struct timeval  tv;
    time_t          now;
    struct tm      *ptm;

    gettimeofday(&tv, NULL);
    now = time(NULL);

    ptm = localtime(&now);
    snprintf(ce_log_time_str, sizeof(ce_log_time_str), "%04d-%02d-%02d %02d:%02d:%02d.%03d",
        ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec,
        tv.tv_usec/1000);
}
