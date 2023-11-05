#include "SaveCommand.hpp"
#include "FileDidNotOpenException.hpp"

#include <fstream>

/// TODO: I don't like this, forgot w, h, x, y version... hdfbigbhfdhv
void SaveCommand::execute(CommandType parsedCmd) {  
    MapPair<Key, Value> pairs = parsedCmd.get<1>();
    std::string fileWPath = pairs["-file"].get<std::string>();
    std::ofstream fileToSave(fileWPath, std::ios::binary);
    if (!fileToSave.is_open()) {
        throw FileDidNotOpenException(fileWPath);
    }
    else if (fileToSave.is_open()) {
        for (const auto& slide : doc_->getSlides()) {
            auto count = 0;
            fileToSave << "slide" << " " << count << std::endl;
            for (const auto& item : slide->getSlide()) {
                fileToSave << item->getID() << " " << item->getType() << " ";
                auto pos = item->getPosition();
                NumberType l = pos.first.first;
                NumberType t = pos.first.second;
                NumberType r = pos.second.first;
                NumberType b = pos.second.second;
                fileToSave << " " << l << " " << t << " " << r << " " << b << " ";
                
                auto attrs = item->getAttributes();
                for (const auto& attr : attrs) {
                    fileToSave << attrs.getKey(attr);
                    if (std::is_same_v<decltype(attr), int>) 
                        fileToSave << attr.get<int>() << " ";
                    else if (std::is_same_v<decltype(attr), double>)
                        fileToSave << attr.get<double>() << " ";
                    else if (std::is_same_v<decltype(attr), std::string>)
                        fileToSave << attr.get<std::string>() << " ";
                }
            }
            fileToSave << std::endl;
            ++count;
        }
    }
    fileToSave.close();
}
