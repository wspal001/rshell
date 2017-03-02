#include "ErrorCommand.hh"
ErrorCommand::ErrorCommand()
{

}
ErrorCommand::ErrorCommand(std::string error)
{
    errorString = error;
}
ErrorCommand::~ErrorCommand()
{

}
int ErrorCommand::execute()
{
    std::cout << errorString << std::endl;
    return 0;
}
