#include "ce_tester.h"

namespace CETester {

TesterReport::TesterReport(std::list<TesterRecord*> &records):
    mRecords(records)
{
    gettimeofday(&mStart, nullptr);
}

TesterReport::~TesterReport() {
    uint32_t    timecost;
    bool        failed = false;
    timeval     end;

    gettimeofday(&end, nullptr);

    timecost = (end.tv_sec - mStart.tv_sec) * 1000
             + (end.tv_usec - mStart.tv_usec) / 1000;

    for (auto p = mRecords.begin(); p != mRecords.end(); ++p) {
        if ((*p)->Failed()) {
            std::cout << "    " << (*p)->Desc() << std::endl;
            failed = true;
        }
    }

    if (failed) {
        std::cout << "  ... Failed";
    } else {
        std::cout << "  ... OK";
    }

    std::cout << "    timecost: " << timecost << "ms\n" << std::endl;
}

}
