#include "ListCommand.hpp"

#include <iostream>

void ListCommand::execute(Map infoMap) {
    auto doc = Application::getDocument();
    auto slide = doc->getSlide(int(toNum(infoMap["-idx"])));
    for (const auto& slide : doc) {
        size_t idx = 0;
        for (const auto& item : slide) {
            auto id = item->getID();
            auto type = item->getType();
            std::cout << "id = " << id << ", type = " << type << std::endl;
        }
        ++idx;
    }
}

