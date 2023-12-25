#ifndef COMMANDD_HPP
#define COMMANDD_HPP

#include "../../zhelpers/Definitions.hpp"
#include "../../zhelpers/Exception.hpp"
#include "../../Data/Document.hpp"

#include <string>

namespace cli {

class Command {
    public:
        virtual void execute() = 0;
        virtual ~Command() = default;
};

}

#endif // COMMANDD_HPP

