#include "AddCommandExecutor.hpp"

#include <iostream>

void AddCommandExecutor::execute (CommandType parsedCmd) {
    ///NOTE: assuming the parsedCmd is validated and ready to go
    // if (std::get<1>(parsedCmd) == "add") {
        std::get<2>(parsedCmd) = id_;
        itemStorage_.push_back({id_, std::get<1>(parsedCmd)});
        std::cout << id_ << std::endl;
        ++id_; 
        ///TODO: check this part, print id after adding
    // }
}