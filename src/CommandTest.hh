#ifndef CommandTest_hh
#define CommandTest_hh
#include "CommandContainer.hh"
class CommandTest : public CommandContainer
{
public:
    CommandTest();
    ~CommandTest();
    CommandTest(std::string string);
private:
};
#endif
