#include "ListCommand.hpp"
#include "../../Application.hpp"

#include <iostream>

ListCommand::ListCommand(const Map& info) :
    infoMap_(info)
{}

void ListCommand::execute() {
    auto app = Application::getApplication();
    auto doc = app->getDocument();
    auto& ostr = app->getCLIController()->getOutputStream();
    // std::cout << "list-i darder " << std::endl;
    int idx = 0;
    for (auto& slide : *doc) {
        ostr << "slide idx: " << idx << "\n";
        for (const auto& item : *slide->getItemGroup()) {
            auto id = item->getID();
            auto type = item->getType();
            ostr << "id = " << id << ", type = " << type << std::endl;
        }
        ++idx;
    }
}

