#include "LoadCommandExecutor.hpp"
#include "../definitions.hpp"

#include <fstream>
#include <sstream>

void LoadCommandExecutor::execute (CommandType parsedCmd) {
    if (std::get<0>(parsedCmd) == "load") {
        std::string fileWPath = std::get<std::string>(std::get<1>(parsedCmd)["-file"]);
        std::ifstream fileToLoad(fileWPath);
        if (fileToLoad.is_open()) {
            std::istream& inputStream = fileToLoad;
            itemStorage_.clear();
            std::string line;
            while (std::getline(inputStream, line)) {
                ItemType newItem = parseLineForLoad(line);
                itemStorage_.push_back(newItem);
            }
            auto finalElemIndex = itemStorage_.size() - 1;
            id_ = std::get<0>(itemStorage_.at(finalElemIndex)) + 1;
        }
    }
}

ItemType LoadCommandExecutor::parseLineForLoad(std::string line) {
    std::istringstream iss(line);
    ID id;
    iss >> id;
    std::map<std::string, ArgumentType> arguments;

    std::string key;
    std::string val;
    while (iss >> key >> val) {
        arguments[key] = defs::parseArgumentValue(val);
    }
    return {id, arguments};
}
