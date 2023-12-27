#include "MoveCommand.hpp"
#include "../../Application.hpp"
#include "../../Director/Director.hpp"

namespace cli {

MoveCommand::MoveCommand(const Map& info) :
    infoMap_(info)
{}

void MoveCommand::execute() {
    auto app = app::Application::getApplication();
    auto dir = app->getDirector();
    auto doc = app->getDocument();
    std::shared_ptr<dir::IAction> action = nullptr;
    
    ID currIdx;
    try { currIdx = defs::toInt(infoMap_["-cidx"]); }
    catch (const std::exception& e) { currIdx = dir->getActiveSlideIdx(); }

    ID newIdx;
    try { newIdx = defs::toInt(infoMap_["-nidx"]); }
    catch (const std::exception& e) { newIdx = dir->getActiveSlideIdx(); }

    auto slide = doc->getSlide(currIdx);
    auto slideAtNewIdx = doc->getSlide(newIdx);
    if (slide && slideAtNewIdx) { action = std::make_shared<dir::MoveSlideAction>(doc, slide, currIdx, newIdx); }
    else if (!slide) { throw InvalidIndexException("Slide not found at index: " + defs::toStr(Value(currIdx))); }
    else if (!slideAtNewIdx) { throw InvalidIndexException("Slide not found at index: " + defs::toStr(Value(newIdx))); }

    if (action) { dir->runAction(action); }
    else { throw InvalidActionException("Action is nullptr"); }
}

}