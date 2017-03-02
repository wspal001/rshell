#include "AndCommand.hh"
AndCommand::AndCommand()
{
    maxSize = 2;
}
AndCommand::~AndCommand()
{

}
bool AndCommand::AddCommand(CommandBase* newCommand)
{
    if(!full())
    {
        CommandList.push_back(newCommand);
    }
    return full();
}
int AndCommand::execute()
{
    //std::cout << "&& execute called size: " << CommandList.size() << " full? " << full() << std::endl;
    if(!full())
    {
        //std::cout << "&& not enough arguments" << std::endl;
        return 0;
    }
    if(CommandList.at(0)->execute() == 0)
    {
        //std::cout << "&& execute(2) called" << std::endl;
        return CommandList.at(1)->execute();
    }
    return 0;
}
