//William
//Spalding
//wspal001@ucr.edu
//861219874
#ifndef CommandObject_hh
#define CommandObject_hh
#include "CommandBase.hh"
#include <fstream>

class CommandObject : public CommandBase
{
    public:
        CommandObject();
        CommandObject(std::string name);
        ~CommandObject();
        //bool setParameters(std::string inputString) = 0;
        std::string getStringForm();
        void setStringForm(std::string name);
        int execute();
    protected:
        std::string stringForm;
};

#include "CommandLine.hh"
#endif
