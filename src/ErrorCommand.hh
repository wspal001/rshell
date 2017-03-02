#ifndef ErrorCommand_hh
#define ErrorCommand_hh
#include "CommandObject.hh"
class ErrorCommand : public CommandObject
{
public:
    ErrorCommand();
    ~ErrorCommand();
    ErrorCommand(std::string error);
    int execute();
private:
    std::string errorString;
};
#endif
