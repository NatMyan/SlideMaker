#include "ListCommand.hpp"

#include <iostream>

void ListCommand::execute(CommandType parsedCmd, std::shared_ptr<Document> doc) {
    for (const auto& slide : doc->getSlides()) {
        auto count = 0;
        std::cout << "slide" << " " << count << std::endl;
        for (const auto& item : slide->getSlide()) {
            std::cout << item->getID() << " " << item->getType() << " ";
        }
        std::cout << std::endl;
        ++count;
    }
}

