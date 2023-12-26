#include "RedoCommand.hpp"
#include "../../Application.hpp"

namespace cli {

RedoCommand::RedoCommand(const Map& info) :
    info_(info)
{}

void RedoCommand::execute() {
    auto app = app::Application::getApplication();
    auto dir = app->getDirector();
    dir->redo();
}

}