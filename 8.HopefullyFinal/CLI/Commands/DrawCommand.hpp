#ifndef DRAW_COMMANDD_HPP
#define DRAW_COMMANDD_HPP

#include "Command.hpp"

class DrawCommand : public Command {
    public:
        DrawCommand(const Map& info);
        void execute();
    
    private:
        std::pair<double, double> calculateImgDocWidthHeight();
        double cmToPixel(double length);

    private:
        Map infoMap_;
};

#endif // DRAW_COMMANDD_HPP