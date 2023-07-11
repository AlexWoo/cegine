#include "ce_core.h"

void ce_update_time() {
    struct timeval  tv;
    time_t          now;
    struct tm      *ptm;

    gettimeofday(&tv, NULL);
    now = time(NULL);

    ptm = localtime(&now);
    sprintf(ce_log_time_str, "%04d-%02d-%02d %02d:%0sd:%02d.%03d",
        ptm->tm_year, ptm->tm_mon, ptm->tm_mday,
        ptm->tm_hour, ptm->tm_min, ptm->tm_sec,
        tv.tv_usec/1000);
}
