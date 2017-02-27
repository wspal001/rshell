#ifndef CommandQuit_hh
#define CommandQuit_hh
#include "CommandObject.hh"
class CommandQuit : public CommandObject
{
public:
    CommandQuit();
    ~CommandQuit();
    int execute();
private:
};
#endif
