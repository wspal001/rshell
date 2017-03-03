#ifndef CommandTest_hh
#define CommandTest_hh
#include "CommandObject.hh"

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

class CommandTest : public CommandObject
{
public:
    CommandTest();
    ~CommandTest();
    CommandTest(std::string string);
    int execute();
private:
    bool e;
    bool f;
    bool d;
};
#endif
