#ifndef ADD_COMMANDD_HPP
#define ADD_COMMANDD_HPP

#include "Command.hpp"

class AddCommand : public Command {
    public:
        AddCommand(const Map& info);
        void execute();

    private:
        Map getRemainingPairs();
        BoundingBox createTheBoundingBox();
        std::shared_ptr<Item> createTheItem();

    private:
        static int itemID_; //TK: This is wrong, itemId_ couldn't be in the command
        Map infoMap_;
};

#endif // ADD_COMMANDD_HPP