//William
//Spalding
//wspal001@ucr.edu
//861219874
#ifndef CommandLine_hh
#define CommandLine_hh
#include "CommandContainer.hh"
    #include "CommandTest.hh"
#include "CommandObject.hh"
    #include "CommandQuit.hh"
#include "CommandFactory.hh"

#include "Tokenizer.hh"
#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string.h>


class CommandLine
{
    public:
        CommandLine();
        ~CommandLine();
        bool takeInput();
        bool runCommands();
        bool parseInput();
        CommandBase* createNewCommand(std::string commandString);
    private:
        std::string inputString;
        //std::vector<std::string> directoryList;
        CommandContainer CommandsToRun;
        //CommandFactory * factory;
};
#endif
