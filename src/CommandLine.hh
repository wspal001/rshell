//William
//Spalding
//wspal001@ucr.edu
//861219874
#ifndef CommandLine_hh
#define CommandLine_hh
#include "CommandContainer.hh"
    #include "CommandTest.hh"
    #include "AndCommand.hh"
    #include "OrCommand.hh"
#include "CommandObject.hh"
    #include "CommandQuit.hh"
    #include "ErrorCommand.hh"
#include "CommandFactory.hh" //doesn't do anything

#include "Tokenizer.hh"
#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <fstream>

class CommandLine
{
    public:
        CommandLine();
        ~CommandLine();
    bool takeInput(std::istream & inputstream);
        bool runCommands();
        bool parseInput();
        CommandBase* createNewCommand(std::string commandString);
        std::string formatForCreatingCommands(std::string stringToFormat);
        CommandBase* createSpecialCommands(std::string string);
    private:
        std::string inputString;
        //std::vector<std::string> directoryList;
        CommandContainer CommandsToRun;
        //CommandFactory * factory;
};
#endif
