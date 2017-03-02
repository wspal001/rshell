 #include "OrCommand.hh"
OrCommand::OrCommand()
{
    maxSize = 2;
}
OrCommand::~OrCommand()
{

}
bool OrCommand::AddCommand(CommandBase* newCommand)
{
    if(!full())
    {
        CommandList.push_back(newCommand);
    }
    return full();
}
int OrCommand::execute()
{
    if(!full())
    {
        //std::cout << "|| not enough arguments" << std::endl;
        return 0;
    }
    int value = CommandList.at(0)->execute();
    if(value == -1) {return value;}
    if(value != 0)
    {
        return CommandList.at(1)->execute();
    }
    return 0;
}
