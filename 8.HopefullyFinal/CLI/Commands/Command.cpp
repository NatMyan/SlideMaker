#include "Command.hpp"

bool Command::isTypeSlide(const std::string& type) {
    return type == "slide";
}

bool Command::isTypeItem(const std::string& type) {
    type == "item";
}
