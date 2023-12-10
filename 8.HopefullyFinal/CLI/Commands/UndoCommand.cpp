#include "UndoCommand.hpp"
#include "../../Application.hpp"

UndoCommand::UndoCommand(const Map& info) :
    info_(info)
{}

void UndoCommand::execute() {
    auto dir = Application::getDirector();
    dir->undo();
}