#include "RedoCommand.hpp"
#include "../../Application.hpp"

RedoCommand::RedoCommand(const Map& info) :
    info_(info)
{}

void RedoCommand::execute() {
    auto app = Application::getApplication();
    auto dir = app->getDirector();
    dir->redo();
}