#ifndef __CE_TESTER_RECORD_H__
#define __CE_TESTER_RECORD_H__

#include "ce_tester.h"

namespace CETester {

class TesterRecord
{
private:
    std::string mTRName;
    int         mTRLine;
    bool        mFailed;

public:
    TesterRecord(std::string name, int line, bool failed);
    ~TesterRecord();

    bool Failed();
    std::string Desc();
};

}

#endif
