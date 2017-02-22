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
    
    //take input
    //std::cout << "$" ;
    //std::cin >> inputString;
    std::getline(std::cin, inputString);
    bool noExit = true;
    //std::cout << "test test test test" << std::endl;
    if(inputString == "exit") {return false;}
    if(parseInput()) {noExit = false;}
    runCommands();
    return noExit;
}
bool CommandLine::runCommands()
{
    //run command
    CommandsToRun.execute();
    return false;
}
bool CommandLine::parseInput()
{
    /*
    CommandBase * newCommand = new CommandObject(inputString);
    CommandsToRun.addCommand(newCommand);
    //std::cout << "commands set" << std::endl;
    */
    
    //seperate input into parts
    //std::cout << "parse called" << std::endl;
    Tokenizer input(inputString);
    input.setDelimiter("#");
    std::string noComments = input.next();
    //std::cout << "no comments: " << noComments << std::endl;
    bool exiting = false;
    std::vector<std::string> guarenteedCommands;
    std::string token;
    input.setString(noComments);
    input.setDelimiter(";");
    while((token = input.next()) != "")
    {
        guarenteedCommands.push_back(token);
        //std::cout << token << "_";
        if(token.find("exit") != std::string::npos)
        {
            exiting = true;
        }
        //std::cout << "command: " << token << std::endl;
    }
    //create command objects
    for(unsigned i = 0; i < guarenteedCommands.size() ; i++)
    {
        //std::cout << "guarenteedCommands: " << guarenteedCommands.at(i);
        CommandBase * newCommand = new CommandObject(guarenteedCommands.at(i));
        CommandsToRun.addCommand(newCommand);
    }
    return exiting;
    //std::cout << std::endl;
    
}

