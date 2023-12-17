#include "ListCommand.hpp"
#include "../../Application.hpp"

#include <iostream>

ListCommand::ListCommand(const Map& info) :
    infoMap_(info)
{}

void ListCommand::execute() {
    auto app = Application::getApplication();
    auto doc = app->getDocument();
    auto ostr = app->getOutputStream();
    auto idx = defs::toInt(infoMap_["-idx"]);
    auto slide = doc->getSlide(idx);
    for (auto& slide : *doc) {
        size_t idx = 0;
        (*ostr) << "slideIdx: " << idx << "\n";
        for (const auto& item : *slide) {
            auto id = item->getID();
            auto type = item->getType();
            (*ostr) << "id = " << id << ", type = " << type << std::endl;
        }
        ++idx;
    }
}

