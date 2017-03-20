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
bool CommandLine::takeInput(std::istream & inputstream)
{
    //get user info
    //std::cout << "taking input" << std::endl;
    if(&inputstream == &std::cin)
    {
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
    }
    
    std::getline(inputstream, inputString);
    //std::cout << "test test test test" << std::endl;
    if(inputString == "exit") {return false;}
    
    parseInput();
    
    return runCommands();
}
bool CommandLine::runCommands()
{
    //run command
    if(CommandsToRun.execute() == -1) {return false;}
    return true; //returns false if exiting
}
bool CommandLine::parseInput()
{

    Tokenizer input(inputString);
    input.setDelimiter("#");
    std::string noComments = input.next();
    //std::cout << "no comments: " << noComments << std::endl;
    bool exiting = false;
    //std::cout << "started making commands" << std::endl;
    CommandsToRun.addCommand(createNewCommand(noComments));
    //std::cout << "finished making commands" << std::endl;
    return exiting;

}

CommandBase* CommandLine::createNewCommand(std::string commandString)
{
    CommandContainer * CreatedCommands = new CommandContainer;
    //std::cout << "started formatting commands" << std::endl;
    std::string formattedString = formatForCreatingCommands(commandString);
    //std::cout << "finished formatting commands" << std::endl;
    Tokenizer tokenizedString(formattedString);
    tokenizedString.setDelimiter(",");
    std::string token;
    std::vector<CommandContainer*> currentCommandStack;
    currentCommandStack.push_back(CreatedCommands);
    //int endContainer = 0;
    while((token = tokenizedString.next()) != "")
    {
        if(token.find_first_not_of(" ") == std::string::npos)
        {
            //tokenizedString.next();
        }
        else if(token == "(")
        {
            CommandContainer* subContainer = new CommandContainer;
            bool full = currentCommandStack.at(currentCommandStack.size() - 1)->addCommand(subContainer);
            if(full)
            {
                //std::cout << "container full" << std::endl;
                currentCommandStack.pop_back();
            }
            currentCommandStack.push_back(subContainer);
            //std::cout << token << "new sub container made" << std::endl;
        }
        else if(token == ")")
        {
            currentCommandStack.pop_back();
            //std::cout << token << "new sub container closed" << std::endl;
        }
        else if(token == ";")
        {
            //std::cout << token << "nothing" << std::endl;
            /*
            CommandObject* empty = new CommandObject("  ");
            bool full = currentCommandStack.at(currentCommandStack.size() - 1)->addCommand(empty);
            if(full)
            {
                //std::cout << "container full" << std::endl;
                currentCommandStack.pop_back();
            }
            */
        }
        else if(token == "&&")
        {
            CommandContainer* andContainer = new AndCommand;
            andContainer->addCommand(currentCommandStack.at(currentCommandStack.size() - 1)->removeLastCommand());
            
            currentCommandStack.at(currentCommandStack.size() - 1)->addCommand(andContainer);
            
            currentCommandStack.push_back(andContainer);
            //endContainer += 2;
            //std::cout << token << "new and container made" << std::endl;
        }
        else if(token == "||")
        {
            CommandContainer* OrContainer = new OrCommand;
            OrContainer->addCommand(currentCommandStack.at(currentCommandStack.size() - 1)->removeLastCommand());
            
            currentCommandStack.at(currentCommandStack.size() - 1)->addCommand(OrContainer);
            
            currentCommandStack.push_back(OrContainer);
            //endContainer += 2;
            //std::cout << token << "new or container made" << std::endl;
        }
        else
        {
            //creates and non-container command
            CommandBase* defaultCommand = createSpecialCommands(token);
            if(currentCommandStack.at(currentCommandStack.size() - 1)->addCommand(defaultCommand))
            {
                //std::cout << "container full" << std::endl;
                currentCommandStack.pop_back();
            }
            //std::cout << token << "new defult made" << std::endl;
        }
        
    }
    
    return CreatedCommands;
}



std::string CommandLine::formatForCreatingCommands(std::string stringToFormat)
{
    std::string parseChar = ",";
    int startingParens = 0;
    int endingPraens = 0;
    int startinBrackets = 0;
    int endingBrackets = 0;
    for(unsigned int i = 0 ; i < stringToFormat.size() ; i++)
    {
        if(stringToFormat.size() < 2)
        {
            return "ERROR please enter a command";
        }
        switch (stringToFormat[i])
        {
            case '(':
                stringToFormat.insert((i + 1), parseChar);
                stringToFormat.insert(i, parseChar);
                i++;
                startingParens++;
                break;
                
            case ')':
                stringToFormat.insert((i + 1), parseChar);
                stringToFormat.insert(i, parseChar);
                i++;
                endingPraens++;
                break;
            case ';':
                stringToFormat.insert((i + 1), parseChar);
                stringToFormat.insert(i, parseChar);
                i++;
                break;
            case '&':
                if((i == stringToFormat.size() - 1) || stringToFormat.at(i + 1) != '&')
                {
                    return "ERROR expected second &";
                }
                stringToFormat.insert((i + 2), parseChar);
                stringToFormat.insert(i, parseChar);
                i += 2;
                break;
            case '|':
                if((i == stringToFormat.size() - 1) || stringToFormat.at(i + 1) != '|')
                {
                    //return "ERROR expected second |";
                }
                else
                {
                stringToFormat.insert((i + 2), parseChar);
                stringToFormat.insert(i, parseChar);
                i += 2;
                }
                break;
            case '[':
                stringToFormat.insert((i + 1), " ");
                //stringToFormat.insert(i, parseChar);
                i++;
                startinBrackets++;
                break;
            case ']':
                //stringToFormat.insert((i + 1), parseChar);
                stringToFormat.insert(i, " ");
                i++;
                endingBrackets++;
                break;
                
            default:
                //i++;
                break;
        }
        //std::cout << stringToFormat << std::endl;
    }
    if(startingParens != endingPraens)
    {
        return "ERROR starting parenthesies does not match ending parenthisis";
    }
    if(startinBrackets != endingBrackets)
    {
        return "ERROR starting brackets does not match ending brackets";
    }
    return stringToFormat;
}

CommandBase* CommandLine::createSpecialCommands(std::string string)
{
    Tokenizer givenString(string);
    std::string subtoken = givenString.next(); //gets first word of command
    if(subtoken == "exit")
    {
        //create quitCommand
        CommandBase* newBase = new CommandQuit;
        return newBase;
    }
    else if(subtoken == "test" || subtoken == "[")
    {
        //create testCommand
        CommandBase* newBase = new CommandTest(string);
        return newBase;
    }
    else if(subtoken == "ERROR")
    {
        //create ErrorCommand
        //std::cout << "quit command created" << std::endl;
        CommandBase* newBase = new ErrorCommand(string);
        return newBase;
    }
    else
    {
        //create defultCommand
        CommandBase* newBase = new CommandObject(string);
        return newBase;
    }
    CommandBase* newBase = new ErrorCommand("ERROR no command created");
    return newBase;
}

