#include "LoadCommand.hpp"
#include "FileDidNotOpenException.hpp"
#include "definitions.hpp"

#include <fstream>

void LoadCommand::execute(CommandType parsedCmd) {
    MapPair<Key, Value> pairs = parsedCmd.get<1>();
    std::string fileWPath = pairs["-file"].get<std::string>();
    std::ifstream fileToLoad(fileWPath, std::ios::binary);
    if (!fileToLoad.is_open()) {
        throw FileDidNotOpenException(fileWPath);
    }
    else if (fileToLoad.is_open()) {
        std::istream& inputStream = fileToLoad;
        /// TODO: memory leak or not ?
        doc_ = std::make_shared<Document>();
        std::string line;
        while (std::getline(inputStream, line)) {
            
        }
    }
}

/*
void LoadCommandExecutor::execute (CommandType parsedCmd) {
    if (std::get<0>(parsedCmd) == "load") {
        std::string fileWPath = std::get<std::string>(std::get<1>(parsedCmd)["-file"]);
        std::ifstream fileToLoad(fileWPath);
        if (fileToLoad.is_open()) {
            std::istream& inputStream = fileToLoad;
            slide_->getSlide().clear();
            std::string line;
            while (std::getline(inputStream, line)) {
                auto newItem = parseLineForLoad(line);
                auto id = std::get<0>(newItem);
                auto attributes = std::get<1>(newItem);
                Shape shape = createShapeFromIDAndAttributes(id, attributes);
                slide_->getSlide().push_back({id, shape});
            }
            auto finalElemIndex = slide_->getSlide().size() - 1;
            id_ = std::get<0>(slide_->getSlide().at(finalElemIndex)) + 1;
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

Shape LoadCommandExecutor::createShapeFromIDAndAttributes(ID id, std::map<std::string, ArgumentType> attributes) {
    Position pos = {
        {defs::convertToDouble(attributes, "-l"), defs::convertToDouble(attributes, "-t")}, 
        {defs::convertToDouble(attributes, "-r"), defs::convertToDouble(attributes, "-b")}
    };
    Type type = std::get<std::string>(attributes["-type"]);
    std::map<std::string, ArgumentType> attrs;
    std::set<std::string> keysToExclude = {"-l", "-t", "-r", "-b", "-type"};
    for (const auto& pair : attributes) {
        if (keysToExclude.find(pair.first) == keysToExclude.end()) {
            attrs[pair.first] = pair.second;
        }
    }
    return Shape{type, id, pos, attrs};
}
*/