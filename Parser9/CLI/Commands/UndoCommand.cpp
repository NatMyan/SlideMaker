#include "UndoCommand.hpp"
#include "../../Application.hpp"

UndoCommand::UndoCommand(const Map& info) :
    info_(info)
{}

void UndoCommand::execute() {
    auto app = Application::getApplication();
    auto dir = app->getDirector();
    dir->undo();
}