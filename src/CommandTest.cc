#include "CommandTest.hh"
CommandTest::CommandTest()
{

}
CommandTest::~CommandTest()
{

}
CommandTest::CommandTest(std::string string)
{
    //stringForm = string;
    e = true;
    d = false;
    f = false;
    Tokenizer fomatString(string);
    std::string token;
    while((token = fomatString.next()) != "" )
    {
        if(token == "-f")
        {
            f = true;
            e = false;
            d = false;
        }
        if(token == "-d")
        {
            d = true;
            f = false;
            e = false;
        }
        if(token != "[" && token != "]" && token != "test")
        {
            stringForm = token;
        }
    }
}
int CommandTest::execute()
{
    //returns zero if exists 1 if it doesn't
    struct stat sb;
    std::cout << "testing" << stringForm << std::endl;

    if(stat(stringForm.c_str() , &sb) == -1)
    {
        std::cout << "(False)" << std::endl;
        return 1;
    }
    if(d)
    {
        if(S_ISDIR(sb.st_mode))
        {
            std::cout << "(True)" << std::endl;
            return 0;
        }
        std::cout << "(False)" << std::endl;
        return 1;
    }
    if(f)
    {
        if(S_ISREG(sb.st_mode))
        {
            std::cout << "(True)" << std::endl;
            return 0;
        }
        std::cout << "(False)" << std::endl;
        return 1;
    }
    
    std::cout << "(True)" << std::endl;//e is true
    return 0;
}

