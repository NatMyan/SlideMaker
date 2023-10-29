#include "AddCommandExecutor.hpp"

#include <iostream>

void AddCommandExecutor::execute (CommandType parsedCmd) {
    ///NOTE: assuming the parsedCmd is validated and ready to go
    std::get<2>(parsedCmd) = id_;
    auto temp = std::get<1>(parsedCmd);
    Position pos = {
        {defs::convertToDouble(temp, "-l"), defs::convertToDouble(temp, "-t")}, 
        {defs::convertToDouble(temp, "-r"), defs::convertToDouble(temp, "-b")}
    };
    ID id = id_;
    Type type = std::get<std::string>(temp["-type"]);
    ShapeFactory rightShape;
    slide_->getSlide().push_back({id_, rightShape.createShape(type, id, pos, temp)});
    std::cout << id_ << std::endl;
    ++id_;  
    ///TODO: check this part, print id after adding
    ///TODO: change temp to attributes only
}