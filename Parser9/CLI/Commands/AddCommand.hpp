#ifndef ADD_COMMANDD_HPP
#define ADD_COMMANDD_HPP

#include "Command.hpp"
#include "../../Data/Item.hpp"

namespace cli {

class AddCommand : public Command {
    struct InvalidSlideException : public Exception { using Exception::Exception; };
    struct InvalidActionException : public Exception { using Exception::Exception; };
    // struct InvalidIndexException : public Exception { using Exception::Exception; };

    public:
        AddCommand(const Map& info);
        void execute();

    private:
        Map getRemainingPairs();
        BoundingBox createTheBoundingBox();
        std::shared_ptr<dat::Item> createTheItem();
        bool isSlide();
        bool isItem();

    private:
        Map infoMap_;
};

}

#endif // ADD_COMMANDD_HPP