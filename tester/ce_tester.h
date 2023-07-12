#ifndef __CE_TESTER_H__
#define __CE_TESTER_H__

#include <sys/time.h>
#include <string.h>

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

#define EXPECT_NE(v1, v2)                                               \
    AddRecord(new TesterRecord(std::string(#v1)+"!="+#v2, __LINE__, v1!=v2))

#define EXPECT_CSTR_EQ(s1, s2)                                          \
    AddRecord(new TesterRecord(std::string(#s1)+"=="+#s2, __LINE__,     \
    strlen(s1)==strlen(s2) && memcmp(s1, s2, strlen(s1)) == 0))

#define EXPECT_CSTR_NE(s1, s2)                                          \
    AddRecord(new TesterRecord(std::string(#s1)+"!="+#s2, __LINE__,     \
    strlen(s1)!=strlen(s2) || memcmp(s1, s2, strlen(s1)) != 0))

}

#endif
