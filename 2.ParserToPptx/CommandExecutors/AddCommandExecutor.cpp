#include "AddCommandExecutor.hpp"

#include <iostream>

void AddCommandExecutor::execute (CommandType parsedCmd) {
    ///NOTE: assuming the parsedCmd is validated and ready to go
        std::get<2>(parsedCmd) = id_;
        auto temp = std::get<1>(parsedCmd);
        Position pos = {{temp["-l"], temp["-t"]}, {temp["-l"], temp["-t"]}};
        ID id = id_;
        Type type = std::get<std::string>(temp["-type"]);
        slide_->getSlide().push_back({id_, Shape{pos, id, type, temp}});
        std::cout << id_ << std::endl;
        ++id_; 
        ///TODO: check this part, print id after adding
        ///TODO: change temp to attributes only
}