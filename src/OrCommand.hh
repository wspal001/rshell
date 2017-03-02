#ifndef OrCommand_hh
#define OrCommand_hh
#include "CommandContainer.hh"
class OrCommand : public CommandContainer
{
public:
    OrCommand();
    ~OrCommand();
    bool AddCommand(CommandBase* newCommand);
    int execute();
private:
};
#endif
