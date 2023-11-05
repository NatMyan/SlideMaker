#include "DisplayCommand.hpp"

#include <iostream>

///TODO: I hate this
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
                std::cout << attrs.getKey(attr);
                if (std::is_same_v<decltype(attr), int>) 
                    std::cout << attr.get<int>() << " ";
                else if (std::is_same_v<decltype(attr), double>)
                    std::cout << attr.get<double>() << " ";
                else if (std::is_same_v<decltype(attr), std::string>)
                    std::cout << attr.get<std::string>() << " ";
            }
        }
        std::cout << std::endl;
        ++count;
    }
}