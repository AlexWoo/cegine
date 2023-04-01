#ifndef __CE_TESTER_CASE_H__
#define __CE_TESTER_CASE_H__

#include "ce_tester.h"

namespace CETester {

class TesterRecord;

class TesterCase
{
private:
    std::string mTCName;
    std::string mTCFile;
    int         mTCLine;

    bool        mTCFailed;

    std::list<TesterRecord*> mTCRecords;

public:
    TesterCase(std::string name, std::string file, int line);
    ~TesterCase();

    void RunCase();
    void AddRecord(TesterRecord *record);
    bool Failed();

protected:
    virtual void TesterCaseImpl() = 0;
};

class TesterCaseList
{
private:
    uint32_t mNrCase;
    uint32_t mNrFailed;

    std::list<TesterCase*> mList;

public:
    TesterCaseList();
    ~TesterCaseList();

    void AddTesterCase(TesterCase *tc);
    void RunAllTesterCase();
};

static TesterCaseList tcList;

}

#endif
