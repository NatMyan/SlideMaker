#include "MoveCommand.hpp"
#include "../../Application.hpp"
#include "../../Director/Director.hpp"

MoveCommand::MoveCommand(const Map& info) :
    infoMap_(info)
{}

void MoveCommand::execute() {
    auto app = Application::getApplication();
    auto dir = app->getDirector();
    std::shared_ptr<IAction> action = nullptr;

    auto doc = app->getDocument();
    auto currentIndex = defs::toInt(infoMap_["-cidx"]); 
    auto newIndex = defs::toInt(infoMap_["-nidx"]);
    auto slide = doc->getSlide(currentIndex);
    action = std::make_shared<MoveSlideAction>(doc, slide, currentIndex, newIndex);

    dir->runAction(action);
}