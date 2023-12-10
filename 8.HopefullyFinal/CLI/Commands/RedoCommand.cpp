#include "RedoCommand.hpp"
#include "../../Application.hpp"

RedoCommand::RedoCommand(const Map& info) :
    info_(info)
{}

void RedoCommand::execute() {
    auto dir = Application::getDirector();
    dir->redo();
}