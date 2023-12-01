#include "LoadSerializer.hpp"
#include "../Exception.hpp"

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
        // auto slide = nDoc_->getSlide(idx_).lock();
        Idx idxl;
        fileToLoad_ >> idxl;
        auto slide = nDoc_->getSlide(idxl).lock();
        
        Type type;
        fileToLoad_ >> type;

        NumberType l, t, r, b;
        // std::string holder; 
        fileToLoad_ >> l >> t >> r >> b;


        
        /*Idx loadedIdx;
        fileToLoad_.read(reinterpret_cast<char*>(&loadedIdx), sizeof(loadedIdx));
        if (loadedIdx != idx_) {
            throw Exception("Mismatched index during loading.");
        }
        int loadedIntAttr;
        fileToLoad_.read(reinterpret_cast<char*>(&loadedIntAttr), sizeof(loadedIntAttr));
        double loadedDoubleAttr;
        fileToLoad_.read(reinterpret_cast<char*>(&loadedDoubleAttr), sizeof(loadedDoubleAttr));
        std::string loadedStrAttr;
        fileToLoad_.read(reinterpret_cast<char*>(&loadedStrAttr), sizeof(loadedStrAttr));*/

        fileToLoad_.close();
    }
}