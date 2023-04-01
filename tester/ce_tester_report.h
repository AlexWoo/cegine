#ifndef __CE_TESTER_REPORT_H__
#define __CE_TESTER_REPORT_H__

#include "ce_tester.h"

namespace CETester {

class TesterReport
{
private:
    std::list<TesterRecord*> &mRecords;
    timeval                  mStart;

public:
    TesterReport(std::list<TesterRecord*> &records);
    ~TesterReport();
};

}

#endif
