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
        bool isArgFound(const std::string& argName);
        bool isSlide();
        bool isItem();

    private:
        Map infoMap_;
};

#endif // ADD_COMMANDD_HPP