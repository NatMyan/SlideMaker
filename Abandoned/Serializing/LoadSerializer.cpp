#include "LoadSerializer.hpp"
#include "../Exception.hpp"
#include "../definitions.hpp"

LoadSerializer::LoadSerializer(std::string fileName, std::ifstream& fileToLoad, std::shared_ptr<Document> nDoc, Idx idx) :
    fileName_(fileName),
    fileToLoad_(fileToLoad),
    nDoc_(nDoc),
    idx_(idx)
{}

void LoadSerializer::execute() {
    //idx id type l t r b attrs
    if (!fileToLoad_.is_open()) {
        throw Exception("File2 failed to open for loading: " + fileName_);
    }
    else if (fileToLoad_.is_open()) {
        Idx idxl;
        fileToLoad_ >> idxl;
        auto slide = nDoc_->getSlide(idxl).lock();
        
        Type type;
        fileToLoad_ >> type;

        NumberType l, t, r, b;
        fileToLoad_ >> l >> t >> r >> b;

        MapPair<Key, Value> pairs;
        std::string key;
        std::string val;
        
        while (fileToLoad_ >> key >> val) {
            auto value = defs::parseArgValue(val);
            pairs[key] = value;
        }
        Attributes attrs(pairs);
        
        fileToLoad_.close();
    }
}