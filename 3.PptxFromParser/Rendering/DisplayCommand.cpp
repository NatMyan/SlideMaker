#include "DisplayCommand.hpp"
#include <iostream>

void DisplayCommand::execute(CommandType parsedCmd) {
    for (const auto& slide : doc_->getSlides()) {
        auto count = 0;
        std::cout << "slide" << " " << count << std::endl;
        for (const auto& item : slide->getSlide()) {
            std::cout << item->getID() << " " << item->getType() << " ";
            auto pos = item->getPosition();
            NumberType l = pos.first.first;
            NumberType t = pos.first.second;
            NumberType r = pos.second.first;
            NumberType b = pos.second.second;
            std::cout << "-l " << l << "-t " << t << "-r " << r << "-b " << b << " ";

            auto attrs = item->getAttributes();
            for (const auto& attr : attrs) {
                std::cout << attrs.getKey(attr) << " " << attr << " ";
            }
        }
        std::cout << std::endl;
        ++count;
    }
}