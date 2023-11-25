#include "LoadCommand.hpp"
#include "Exception.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

/// TODO: such bad code, forgot w, h, x, y version... hdfbigbhfdhv
void LoadCommand::execute(CommandType parsedCmd, std::shared_ptr<Document> doc, std::shared_ptr<Director> dir) {
    MapPair<Key, Value> pairs = parsedCmd.get<1>();
    std::string fileWPath;
    fileWPath = pairs["-file"].get<std::string>();
    std::ifstream fileToLoad(fileWPath, std::ios::binary);
    if (!fileToLoad.is_open()) {
        throw Exception("File didn't open: " + fileWPath);
    }
    else if (fileToLoad.is_open()) {
        auto nDoc = std::make_shared<Document>(); // memory leak ?
        Idx idx = 0;
        LoadAction l(nDoc, idx);
        l.execute();
    }
}

/*std::istream& inputStream = fileToLoad;
        /// TODO: memory leak or not ?
        doc = std::make_shared<Document>();
        std::string line;
        // id type pos: l t r b attrs: key val
        while (std::getline(inputStream, line)) {
            std::istringstream is(line);
            std::string token;
            is >> token;
            is >> token;
            Idx idx = std::stoi(token);
            doc->addtoDocument(std::make_shared<Slide>());
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
                auto slide = doc->getSlide(idx).lock();
                slide->addtoSlide(ItemFactory::createItem(type, id, pos, attrs));
            }
        }*/