#ifndef ACTION_TAKER_HPP
#define ACTION_TAKER_HPP

#include "../CmdLineInterface/CommandFactory.hpp"

class ActionTaker {
    public:
        void execute (CommandType parsedCmd, std::shared_ptr<Document> doc);
};

#endif // ACTION_TAKER_HPP