#include "LoadCommandExecutor.hpp"

#include <fstream>
#include <sstream>

void LoadCommandExecutor::execute (CommandType parsedCmd) {
    if (std::get<1>(parsedCmd) == "load") {
        std::string fileWPath = std::get<std::string>(std::get<2>(parsedCmd)["-file"]);
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
        arguments[key] = parseArgumentValue(val);
    }
    return {id, arguments};
}

/// TODO: fix code duplication -> appears in Parser4
ArgumentType LoadCommandExecutor::parseArgumentValue(const std::string& argValue) { 
    try {
        return std::stoi(argValue);
    } catch (const std::invalid_argument&) {
        try {
            return std::stod(argValue);
        } catch (const std::invalid_argument&) {
            return argValue;
        }
    }
    return argValue;
}