#include "ExitCommand.hpp"
#include "../../Application.hpp"

ExitCommand::ExitCommand(const Map& info) :
    info_(info)
{}

void ExitCommand::execute() {
    auto app = Application::getApplication();
    app->quit();
}