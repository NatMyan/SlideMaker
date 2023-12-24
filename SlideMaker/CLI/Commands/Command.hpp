#ifndef COMMANDD_HPP
#define COMMANDD_HPP

#include "../../definitions.hpp"
#include "../../Data/Document.hpp"

#include <string>

class Command {
    public:
        virtual void execute() = 0;
        virtual ~Command() = default;
};

#endif // COMMANDD_HPP

