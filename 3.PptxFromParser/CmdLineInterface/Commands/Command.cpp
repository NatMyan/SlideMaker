#include "Command.hpp"
#include "../../Data/Items/ShapeRegistry.hpp"
#include "../../Exception.hpp"

#include <iostream>

int Command::itemId_ = 0;

bool Command::isTypeSlide (MapPair<Key, Value> pairs) {
    return pairs["-type"].get<std::string>() == "slide";
}

///TODO: should this exist or should I assume validator works and write else ?
bool Command::isTypeItem(MapPair<Key, Value> pairs) {
    if (pairs["-type"].holdsAlternative<std::string>()) {
            ShapeRegistry shapeReg;
        try {
            shapeReg.findShape(pairs["-type"].get<std::string>());
        } catch (const Exception&) {
            return false;
        }
        return true;
    } 
    return false;
    ///NOTE: theoretically, it shouldn't reach here ^
}