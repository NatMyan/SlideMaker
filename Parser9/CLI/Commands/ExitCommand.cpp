#include "ExitCommand.hpp"
#include "../../Application.hpp"

namespace cli {

ExitCommand::ExitCommand(const Map& info) :
    info_(info)
{}

void ExitCommand::execute() {
    auto app = app::Application::getApplication();
    app->quit();
}

}