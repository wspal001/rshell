//William
//Spalding
//wspal001@ucr.edu
//861219874
#include <iostream>
#include <vector>

#include "CommandBase.hh"
    #include "CommandContainer.hh"
    #include "CommandComment.hh"
    #include "CommandObject.hh"
#include "CommandLine.hh"
#include "CommandFactory.hh"

using namespace std;

int main(int argc, char **argv)
{
    CommandLine* activeLine = new CommandLine();
    //std::vector<CommandBase*> validCommands;
    while( activeLine->takeInput() )
    {
        //std::cout << "inside While loop" << std::endl;
    }
    //cout << "shit works" << endl;
    return 0;
}
//g++ main.cc CommandBase.cc CommandComment.cc CommandContainer.cc CommandLine.cc CommandObject.cc Tokenizer.cc -Wall -Werror -o a.out
