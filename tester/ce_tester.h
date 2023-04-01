#ifndef __CE_TESTER_H__
#define __CE_TESTER_H__

#include <sys/time.h>

#include <list>
#include <string>
#include <iostream>

#include "ce_tester_case.h"
#include "ce_tester_macro.h"
#include "ce_tester_record.h"
#include "ce_tester_report.h"

namespace CETester {

#define RunAllTester tcList.RunAllTesterCase 

#define EXPECT_EQ(v1, v2)                                               \
    AddRecord(new TesterRecord(std::string(#v1)+"=="+#v2, __LINE__, v1==v2))

}

#endif
