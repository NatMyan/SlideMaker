#include "LoadAction.hpp"
#include "../Exception.hpp"

LoadAction::LoadAction(std::string fileName, std::ifstream& fileToLoad,std::shared_ptr<Document> nDoc, Idx idx) :
    fileName_(fileName),
    fileToLoad_(fileToLoad),
    nDoc_(nDoc),
    idx_(idx)
{}

void LoadAction::execute() {
    if (!fileToLoad_.is_open()) {
        throw Exception("File2 failed to open for loading: " + fileName_);
    }
    else if (fileToLoad_.is_open()) {
        Idx loadedIdx;
        fileToLoad_.read(reinterpret_cast<char*>(&loadedIdx), sizeof(loadedIdx));

        // Check if the loaded index matches the expected index
        if (loadedIdx != idx_) {
            throw Exception("Mismatched index during loading.");
        }

        // Read and load other data from the file as needed

        // Example: Read and load an integer attribute
        int loadedIntAttr;
        fileToLoad_.read(reinterpret_cast<char*>(&loadedIntAttr), sizeof(loadedIntAttr));
        // Use loadedIntAttr to populate your Document or take appropriate action

        // Example: Read and load a double attribute
        double loadedDoubleAttr;
        fileToLoad_.read(reinterpret_cast<char*>(&loadedDoubleAttr), sizeof(loadedDoubleAttr));
        // Use loadedDoubleAttr to populate your Document or take appropriate action

        // Example: Read and load a string attribute
        std::string loadedStrAttr;
        fileToLoad_.read(reinterpret_cast<char*>(&loadedStrAttr), sizeof(loadedStrAttr));
        // Use loadedStrAttr to populate your Document or take appropriate action

        // Continue reading and loading other data as needed

        // Close the file when done
        fileToLoad_.close();
    }
}