#ifndef __CE_TESTER_MACRO_H__
#define __CE_TESTER_MACRO_H__

#include "ce_tester.h"

namespace CETester {

#define CE_TESTCASE(name)                                           \
class TesterCase ## name: public TesterCase                         \
{                                                                   \
public:                                                             \
    TesterCase ## name(): TesterCase(#name, __FILE__, __LINE__) {   \
        tcList.AddTesterCase(this);                                 \
    }                                                               \
                                                                    \
protected:                                                          \
    virtual void TesterCaseImpl() override;                         \
};                                                                  \
                                                                    \
static TesterCase ## name tc ## name;                               \
                                                                    \
void TesterCase ## name::TesterCaseImpl()

}

#endif
