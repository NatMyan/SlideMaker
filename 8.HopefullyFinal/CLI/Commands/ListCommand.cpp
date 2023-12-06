#include "ListCommand.hpp"

#include <iostream>

ListCommand::ListCommand(const Map& info) :
    infoMap_(info)
{}

void ListCommand::execute() {
    auto doc = Application::getDocument();
    auto idx = int(toNum(infoMap_["-idx"]));
    auto slide = doc->getSlide(idx);
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

