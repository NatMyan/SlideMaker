#include "CommandExecutor.hpp"
#include "../ShapeRegistry.hpp"
#include "../Items/WrongShapeException.hpp"

bool CommandExecutor::isTypeSlide (MapPair<Key, Value> pairs) {
    return pairs["-type"].get<std::string>() == "slide";
}

///TODO: should this exist or should I assume validator works and write else ?
bool CommandExecutor::isTypeItem(MapPair<Key, Value> pairs) {
    try {
        ShapeRegistry shapeReg;
        shapeReg.findShape(pairs["-type"].get<std::string>());
    } 
    catch (const WrongShapeException& e) {
        return false;  
    }
    return true;
}