#include "Command.hpp"
#include "../../Data/Items/ShapeRegistry.hpp"
#include "../../Data/Items/WrongShapeException.hpp"

int Command::itemId_ = 0;

bool Command::isTypeSlide (MapPair<Key, Value> pairs) {
    return pairs["-type"].get<std::string>() == "slide";
}

///TODO: should this exist or should I assume validator works and write else ?
bool Command::isTypeItem(MapPair<Key, Value> pairs) {
    try {
        ShapeRegistry shapeReg;
        shapeReg.findShape(pairs["-type"].get<std::string>());
    } 
    catch (const WrongShapeException& e) {
        return false;  
    }
    return true;
}