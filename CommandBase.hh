//William
//Spalding
//wspal001@ucr.edu
//861219874
#ifndef CommandBase_hh
#define CommandBase_hh
#include <vector>
#include <iostream>
#include <stdlib.h>
class CommandBase
{
    public:
        CommandBase();
        virtual ~CommandBase();
        virtual int execute() = 0;
    private:
    
    
private:
};
#endif
