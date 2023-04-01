#include "ce_tester.h"

namespace CETester {

TesterRecord::TesterRecord(std::string name, int line, bool failed):
    mTRName(name), mTRLine(line), mFailed(!failed)
{
}

TesterRecord::~TesterRecord() {
}

bool TesterRecord::Failed() {
    return mFailed;
}

std::string TesterRecord::Desc() {
    if (!mFailed) {
        return "Expected result: " + mTRName +
               " at line: " + std::to_string(mTRLine);
    }
    return "Unexpected result: " + mTRName +
           " at line: " + std::to_string(mTRLine);
}

}
