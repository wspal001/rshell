#ifndef AndCommand_hh
#define AndCommand_hh
#include "CommandContainer.hh"
class AndCommand : public CommandContainer
{
public:
    AndCommand();
    ~AndCommand();
    bool AddCommand(CommandBase* newCommand);
    int execute();
private:
};
#endif
