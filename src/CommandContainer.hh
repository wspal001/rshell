 //William
//Spalding
//wspal001@ucr.edu
//861219874
#ifndef CommandContainer_hh
#define CommandContainer_hh
#include "CommandBase.hh"
#include <limits>
class CommandContainer : public CommandBase
{
    public:
        CommandContainer();
        ~CommandContainer();
        int execute();
        bool addCommand(CommandBase* newCommand);
        CommandBase* removeLastCommand();
        bool full();
    protected:
        std::vector<CommandBase*> CommandList;
        int maxSize;
};
#endif
