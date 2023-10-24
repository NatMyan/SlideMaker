#include "RemoveCommandExecutor.hpp"

void RemoveCommandExecutor::execute (CommandType parsedCmd) {
    ///NOTE: assuming the parsedCmd is validated and ready to go
    if (std::get<0>(parsedCmd) == "remove") {
        for (const auto& item : slide_->getSlide()) {
            int itemID = std::get<0>(item);
            int removerID = std::get<int>(std::get<1>(parsedCmd)["-id"]);
            if (itemID == removerID) {
                slide_->getSlide().erase(std::remove(slide_->getSlide().begin(), slide_->getSlide().end(), item), slide_->getSlide().end());
            } 
        }
    }
}

// myVector2.erase(std::remove(myVector2.begin(), myVector2.end(), valueToRemove), myVector2.end());