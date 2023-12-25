#ifndef COMMAND_REGISTRYY_HPP
#define COMMAND_REGISTRYY_HPP

#include "../../zhelpers/Definitions.hpp"
#include "../../zhelpers/Exception.hpp"

namespace cli {

class CommandRegistry {
    struct InvalidCommandNameException : public Exception { using Exception::Exception; };

    public:
        CommandRegistry();
        
    public:
        std::string findCommandName (const std::string& cmdName) const; // commandName is from takeToken
        std::vector<CommandTemplate>::iterator findCmdIter(const std::string& cmdName);
        std::vector<CommandTemplate> getCommandTemplates();
        
    private:
        std::vector<CommandTemplate> cmdTemplates_;
};

}

#endif // COMMAND_REGISTRYY_HPP