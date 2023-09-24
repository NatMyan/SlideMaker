#include "AddCommandExecutor.hpp"

void AddCommandExecutor::execute (CommandType parsedCmd) {
    ///NOTE: assuming the parsedCmd is validated and ready to go
    if (std::get<1>(parsedCmd) == "add") {
        std::get<0>(parsedCmd) = index_;
        itemStorage_.push_back(std::get<2>(parsedCmd));
        ++index_; 
        ///TODO: check this part
    }
}