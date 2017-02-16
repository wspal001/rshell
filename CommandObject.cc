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
    stringForm = name;
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
    stringForm = name;
}
int CommandObject::execute()
{
    return system(stringForm.c_str());
}


