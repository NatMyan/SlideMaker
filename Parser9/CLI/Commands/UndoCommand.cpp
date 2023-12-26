#include "UndoCommand.hpp"
#include "../../Application.hpp"

namespace cli {

UndoCommand::UndoCommand(const Map& info) :
    info_(info)
{}

void UndoCommand::execute() {
    auto app = app::Application::getApplication();
    auto dir = app->getDirector();
    dir->undo();
}

}