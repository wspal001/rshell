#ifndef CommandFactory_hh
#define CommandFactory_hh
#include "CommandBase.hh"
#include "CommandContainer.hh"
#include "CommandObject.hh"

#include "Tokenizer.hh"
#include <iostream>
class CommandFactory
{
    public:
        CommandFactory();
        ~CommandFactory();
        CommandBase * createCommand(std::string stringForm);//returns both commands and commandContainers
    
    private:
};
#endif
