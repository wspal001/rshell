//William
//Spalding
//wspal001@ucr.edu
//861219874
#include "CommandContainer.hh"

CommandContainer::CommandContainer()
{
    maxSize = std::numeric_limits<int>::max();
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
    //std::cout << "container execute called" << std::endl;
    int success = 0;
    for(unsigned i = 0; i < CommandList.size() ; i++)
    {
        success = CommandList.at(i)->execute();
        //delete(CommandList.at(i));
        if(success == -1) {return success;}
    }
    CommandList.clear();
    return success;
}
bool CommandContainer::addCommand(CommandBase* newCommand)
{
    CommandList.push_back(newCommand);
    return full();
}
CommandBase* CommandContainer::removeLastCommand()
{
    CommandBase* target = CommandList.at(CommandList.size() - 1);
    CommandList.pop_back();
    return target;
}
bool CommandContainer::full()
{
    return (CommandList.size() >= maxSize);
}
