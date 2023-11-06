#include "LoadCommand.hpp"
#include "FileDidNotOpenException.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

/// TODO: such bad code, forgot w, h, x, y version... hdfbigbhfdhv
void LoadCommand::execute(CommandType parsedCmd) {
    MapPair<Key, Value> pairs = parsedCmd.get<1>();
    std::string fileWPath;
    try {
        fileWPath = pairs["-file"].get<std::string>();
    } catch (const std::bad_variant_access&) {
        std::cerr << "file existeth not" << std::endl;
    }
    std::ifstream fileToLoad(fileWPath, std::ios::binary);
    if (!fileToLoad.is_open()) {
        throw FileDidNotOpenException(fileWPath);
    }
    else if (fileToLoad.is_open()) {
        std::istream& inputStream = fileToLoad;
        /// TODO: memory leak or not ?
        doc_ = std::make_shared<Document>();
        std::string line;
        // id type pos: l t r b attrs: key val
        while (std::getline(inputStream, line)) {
            std::istringstream is(line);
            std::string token;
            is >> token;
            is >> token;
            Idx idx = std::stoi(token);
            doc_->addtoDocument(std::make_shared<Slide>());
            while (std::getline(inputStream, line)) {
                std::istringstream iss(line);
                iss >> token;
                ID id = std::stoi(token);
                iss >> token;
                Type type = token;
                iss >> token;
                NumberType l = defs::convertToDouble(defs::parseArgValue(token));
                iss >> token;
                NumberType t = defs::convertToDouble(defs::parseArgValue(token));
                iss >> token;
                NumberType r = defs::convertToDouble(defs::parseArgValue(token));
                iss >> token;
                NumberType b = defs::convertToDouble(defs::parseArgValue(token));
                Position pos = {{l, t}, {r, b}};
                std::string key, value;
                MapPair<Key, Value> mapPairs;
                Attributes attrs(mapPairs);
                while (iss >> key >> value) {
                    attrs.setPair(key, defs::parseArgValue(value));
                }
                auto slide = doc_->getSlide(idx).lock();
                slide->addtoSlide(ItemFactory::createItem(type, id, pos, attrs));
            }
        }
    }
}
