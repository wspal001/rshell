//William
//Spalding
//wspal001@ucr.edu
//861219874
#include "CommandObject.hh"
CommandObject::CommandObject()
{
    //std::cout << "object made" << std::endl;
}
CommandObject::CommandObject(std::string name)
{
    int start = name.find_first_not_of(" ");
    if(start == std::string::npos){stringForm = " "; return;}
    int end = name.find_last_not_of(" ");
    int range = end - start + 1;
    stringForm = name.substr(start,range);
    //std::cout << stringForm << std::endl;
    //std::cout << "object made" << std::endl;
}
CommandObject::~CommandObject()
{
    //std::cout << "object deleted" << std::endl;
}
std::string CommandObject::getStringForm()
{
    return stringForm;
}
void CommandObject::setStringForm(std::string name)
{
    int start = name.find_first_not_of(" ");
    int end = name.find_last_not_of(" ");
    int range = end - start + 1;
    stringForm = name.substr(start,range);
    //std::cout << stringForm << std::endl;
}
int CommandObject::execute()
{
    /*
    char *argv[64]
    unsigned int i = 0;
    
    pid_t pid;
    int status;
    if((pid = fork()) < 0)
    {//error forking child
        perror("Fork failed");
    }
    else if(pid == 0)
    {
        if(execvp() )
    }
    */
    std::ifstream testFile;
    testFile.open(stringForm.c_str());
    if(testFile.is_open())
    {
        //std::cout << "file opened" << std::endl;
        std::string input;
        CommandLine* testLine = new CommandLine;
        getline(testFile,input);
        while(!testFile.eof())
        {
            //getline(testFile, input);
            if(!testLine->takeInput(testFile))
            {
                return -1;
            }
        }
        return 0;
    } //else {std::cout << "file not opened" << std::endl;}
    else {return system(stringForm.c_str());}
}


