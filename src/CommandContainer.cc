//William
//Spalding
//wspal001@ucr.edu
//861219874
#include "CommandContainer.hh"

CommandContainer::CommandContainer()
{

}
CommandContainer::~CommandContainer()
{

    for(unsigned i = 0 ; i < CommandList.size() ; i++)
    {
        delete(CommandList.at(i));
    }

}
int CommandContainer::execute()
{
    int success = 0;
    for(unsigned i = 0; i < CommandList.size() ; i++)
    {
        success = CommandList.at(i)->execute();
        delete(CommandList.at(i));
        if(!success) {}
    }
    CommandList.clear();
    return success;
}
void CommandContainer::addCommand(CommandBase* newCommand)
{
    CommandList.push_back(newCommand);
}
