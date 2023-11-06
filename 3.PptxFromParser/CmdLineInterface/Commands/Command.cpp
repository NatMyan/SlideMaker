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
    try {
        ShapeRegistry shapeReg;
        try {
            shapeReg.findShape(pairs["-type"].get<std::string>());
        } catch (const std::bad_variant_access&) {
            std::cerr << "in shapeReg not found in isTypeItem" << std::endl;
            return false;
        }
    } 
    catch (const Exception& e) {
        return false;  
    }
    return true;
}