#ifndef __CE_TESTER_H__
#define __CE_TESTER_H__

#include <sys/time.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

#include <list>
#include <string>
#include <iostream>

#include "ce_tester_case.h"
#include "ce_tester_macro.h"
#include "ce_tester_record.h"
#include "ce_tester_report.h"

namespace CETester {

#define RunAllTester tcList.RunAllTesterCase 

#define TestPrint(format, ...)                                          \
    printf("    ");                                                     \
    printf(format, ##__VA_ARGS__);                                      \
    printf("\n")

#define EXPECT_EQ(v1, v2)                                               \
    AddRecord(new TesterRecord(std::string(#v1)+"=="+#v2, __LINE__, v1==v2))

#define EXPECT_NE(v1, v2)                                               \
    AddRecord(new TesterRecord(std::string(#v1)+"!="+#v2, __LINE__, v1!=v2))

#define EXPECT_CSTR_EQ(s1, s2)                                          \
    AddRecord(new TesterRecord(std::string(#s1)+"=="+#s2, __LINE__,     \
    strlen((char*)s1)==strlen((char*)s2) && memcmp(s1, s2, strlen((char*)s1)) == 0))

#define EXPECT_CSTR_NE(s1, s2)                                          \
    AddRecord(new TesterRecord(std::string(#s1)+"!="+#s2, __LINE__,     \
    strlen((char*)s1)!=strlen((char*)s2) || memcmp(s1, s2, strlen((char*)s1)) != 0))

#define EXPECT_FILESIZE(path, size) {                                   \
    struct stat st;                                                     \
    int fd = open(path, O_RDONLY, 0644);                                \
    fstat(fd, &st);                                                     \
    AddRecord(new TesterRecord(                                         \
        std::string("File(")+#path+") size is "+#size, __LINE__,        \
        st.st_size==size));                                             \
    close(fd);                                                          \
}

#define EXPECT_FILESIZE_FD(fd, size) {                                  \
    struct stat st;                                                     \
    fstat(fd, &st);                                                     \
    AddRecord(new TesterRecord(                                         \
        std::string("File(")+#fd+") size is "+#size, __LINE__,          \
        st.st_size==size));                                             \
}

}

#endif
