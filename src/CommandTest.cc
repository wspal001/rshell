#include "CommandTest.hh"
CommandTest::CommandTest()
{

}
CommandTest::~CommandTest()
{

}
CommandTest::CommandTest(std::string string)
{
    stringForm = string;
}
int CommandTest::execute()
{
    std::cout << "testing" << stringForm << std::endl;
    return 0;
}

