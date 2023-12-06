#include "UndoCommand.hpp"

UndoCommand::UndoCommand(const Map& info) :
    info_(info)
{}

void UndoCommand::execute() {
    auto dir = Application::getDirector();
    dir->undo();
}