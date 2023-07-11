#ifndef __CE_TIME_H_
#define __CE_TIME_H_

#include "ce_core.h"

unsigned char ce_log_time_str[sizeof("1970-00-00 00:00:00.000")];

void ce_update_time();

#endif
