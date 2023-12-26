#include "SwitchCommand.hpp"
#include "../../Application.hpp"

namespace cli {

SwitchCommand::SwitchCommand(const Map& info) :
    infoMap_(info)
{}

void SwitchCommand::execute() {
    auto app = app::Application::getApplication();
    auto dir = app->getDirector();

    ID idx;
    try { idx = defs::toInt(infoMap_["-idx"]); }
    catch (const std::exception& e) { idx = dir->getActiveSlideIdx(); }

    auto slideToSetActive = app->getDocument()->getSlide(idx);
    if (slideToSetActive) { dir->setActiveSlide(idx); }
    else { throw InvalidIndexException("Slide is nullptr"); }
}

}