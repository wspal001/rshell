//William
//Spalding
//wspal001@ucr.edu
//861219874
#include "CommandLine.hh"

CommandLine::CommandLine()
{
    
}
CommandLine::~CommandLine()
{
    
}
bool CommandLine::takeInput()
{
    //get user info
    char hostname[1024];
    int result = gethostname(hostname, 1024);
    passwd* username = getpwuid(getuid());
    
    if(username == NULL || result != 0)
    {
        std::cout << "$ ";
    }
    else
    {
        std::cout << username->pw_name << "@" << hostname << "$ ";
    }
    
    std::getline(std::cin, inputString);
    //std::cout << "test test test test" << std::endl;
    if(inputString == "exit") {return false;}
    
    parseInput();
    
    return runCommands();
}
bool CommandLine::runCommands()
{
    //run command
    CommandsToRun.execute();
    return true; //returns false if exiting
}
bool CommandLine::parseInput()
{

    Tokenizer input(inputString);
    input.setDelimiter("#");
    std::string noComments = input.next();
    //std::cout << "no comments: " << noComments << std::endl;
    bool exiting = false;
    
    std::vector<std::string> guarenteedCommands; //string forms of each command
    std::string token;
    input.setString(noComments);
    input.setDelimiter(";");
    while((token = input.next()) != "")
    {
        guarenteedCommands.push_back(token);
        
    }
    //create command objects
    for(unsigned i = 0; i < guarenteedCommands.size() ; i++)
    {
        
    }
    return exiting;
    //std::cout << std::endl;
    
}
/*
CommandBase* CommandLine::createNewCommand(std::string commandString)
{
    
    switch (commandString)
    {
        case <#constant#>:
            <#statements#>
            break;
            
        default:
            break;
    }
}
*/
