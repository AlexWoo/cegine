#include "ce_tester.h"

namespace CETester {

TesterCase::TesterCase(std::string name, std::string file, int line):
    mTCName(name), mTCFile(file), mTCLine(line), mTCFailed(false)
{
}

TesterCase::~TesterCase() {
}

void TesterCase::RunCase() {
    std::cout << "  Start run tester case: " << mTCName
              << " (" << mTCFile << ":" << mTCLine << ")" << std::endl;

    TesterReport report(mTCRecords);

    TesterCaseImpl();
}

void TesterCase::AddRecord(TesterRecord *record) {
    mTCRecords.push_back(record);
    if (record->Failed()) {
        mTCFailed = true;
    }
}

bool TesterCase::Failed() {
    return mTCFailed;
}

TesterCaseList::TesterCaseList(): mNrCase(0), mNrFailed(0) {
}

TesterCaseList::~TesterCaseList() {
}

void TesterCaseList::AddTesterCase(TesterCase *tc) {
    mList.push_back(tc);
}

void TesterCaseList::RunAllTesterCase() {
    timeval start, end;
    uint32_t timecost;

    std::cout << "CEngine Unittest CETester Start ...\n" << std::endl;

    gettimeofday(&start, nullptr);

    for (auto p = mList.begin(); p != mList.end(); ++p) {
        (*p)->RunCase();
        ++mNrCase;
        if ((*p)->Failed()) {
            ++mNrFailed;
        }
    }

    gettimeofday(&end, nullptr);
    timecost = (end.tv_sec - start.tv_sec) * 1000
             + (end.tv_usec - start.tv_usec) / 1000;

    std::cout << "\n";

    if (mNrFailed > 0) {
        std::cout << "Tester Failed!!!";
    } else {
        std::cout << "Test Passed!!!";
    }

    std::cout << " Total cases: " << mNrCase
              << ", " << mNrCase - mNrFailed << " passed"
              << ", " << mNrFailed << " failed"
              << ", cost " << timecost << "ms" << std::endl;
}

}
