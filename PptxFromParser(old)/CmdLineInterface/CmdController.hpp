#ifndef CMD_CONTROLLER_HPP
#define CMD_CONTROLLER_HPP

#include <istream>

class CmdController {
    public:
        void run(std::istream& input);

    private:
        void exec(std::istream& input);
    
    private:
        bool exit = false;
};

#endif // CMD_CONTROLLER_HPP