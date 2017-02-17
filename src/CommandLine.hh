//William
//Spalding
//wspal001@ucr.edu
//861219874
#ifndef CommandLine_hh
#define CommandLine_hh
#include "CommandContainer.hh"
#include "CommandObject.hh"
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
        void runCommands();
        bool parseInput();
    private:
        std::string inputString;
        //std::vector<std::string> directoryList;
        CommandContainer CommandsToRun;
};
#endif
