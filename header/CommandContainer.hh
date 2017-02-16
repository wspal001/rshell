//William
//Spalding
//wspal001@ucr.edu
//861219874
#ifndef CommandContainer_hh
#define CommandContainer_hh
#include "CommandBase.hh"
class CommandContainer : public CommandBase
{
    public:
        CommandContainer();
        ~CommandContainer();
        int execute();
        void addCommand(CommandBase* newCommand);
    private:
        std::vector<CommandBase*> CommandList;
};
#endif
