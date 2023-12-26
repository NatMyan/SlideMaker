#include "ListCommand.hpp"
#include "../../Application.hpp"

#include <iostream>

namespace cli {

ListCommand::ListCommand(const Map& info) :
    infoMap_(info)
{}

void ListCommand::execute() {
    auto app = app::Application::getApplication();
    auto doc = app->getDocument();
    auto& ostr = app->getController()->getOutputStream();

    int idx = 0;
    for (auto& slide : *doc) {
        ostr << "slide idx: " << idx << "\n";
        auto group = slide->getItemGroup();
        if (group) {
            for (const auto& item : *group) {
                ostr << "id = " << item->getID() << ", type = " << item->getType() << std::endl;
            }
        }
        else { throw GroupNotFoundException("Item group is nullptr"); }
        ++idx;
    }
}

}