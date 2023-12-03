#include "SaveItemToFileSerializer.hpp"
#include "Exception.hpp"

SaveItemToFileSerializer::SaveItemToFileSerializer(std::string fileName, std::ofstream& fileToSave, Idx idx, std::shared_ptr<Item> item) :
    fileName_(fileName),
    fileToSave_(fileToSave),
    idx_(idx),
    item_(item)
{}

///TODO: to_string().c_str(), remove reinterpret_cast-s
//idx id type l t r b attrs
void SaveItemToFileSerializer::execute() {
    if (!fileToSave_.is_open()) {
        throw Exception("File2 failed to open: " + fileName_);
    }
    else if (fileToSave_.is_open()) {
        fileToSave_ << idx_ << " ";

        auto id = item_->getID();
        fileToSave_ << id << " ";
        
        auto type = item_->getType();
        fileToSave_ << type << " ";

        auto pos = item_->getPosition();
        NumberType l = pos.first.first;
        fileToSave_ << l << " ";
  
        NumberType t = pos.first.second;
        fileToSave_ << t << " ";
 
        NumberType r = pos.second.first;
        fileToSave_ << r << " ";

        NumberType b = pos.second.second;
        fileToSave_ << b << " ";

        auto attrs = item_->getAttributes();
        for (const auto& attr : attrs) {
            auto key = attrs.getKey(attr);
            fileToSave_ << key << " ";
            if (std::is_same_v<decltype(attr), int> && attr.holdsAlternative<int>()) {
                auto intAttr = attr.get<int>();
                fileToSave_ << intAttr << " ";
            }
            else if (std::is_same_v<decltype(attr), double> && attr.holdsAlternative<double>()) {
                auto doubleAttr = attr.get<double>();
                fileToSave_ << doubleAttr << " ";
            }
            else if (std::is_same_v<decltype(attr), std::string> && attr.holdsAlternative<std::string>()) {
                auto strAttr = attr.get<std::string>();
                fileToSave_ << strAttr << " ";
            }
        }
    }
}

/*
    std::cout << idx_ << ": " << item_->getID() << " " << item_->getType() << " ";
    auto pos = item_->getPosition();
    NumberType l = pos.first.first;
    NumberType t = pos.first.second;
    NumberType r = pos.second.first;
    NumberType b = pos.second.second;
    std::cout << "-l " << l << "-t " << t << "-r " << r << "-b " << b << " ";
    auto attrs = item_->getAttributes();
    for (const auto& attr : attrs) {
        std::cout << attrs.getKey(attr);
        if (std::is_same_v<decltype(attr), int> && attr.holdsAlternative<int>()) {
            std::cout << attr.get<int>() << " ";
        }
        else if (std::is_same_v<decltype(attr), double> && attr.holdsAlternative<double>()) {
            std::cout << attr.get<double>() << " ";
        }
        else if (std::is_same_v<decltype(attr), std::string> && attr.holdsAlternative<std::string>()) {
            std::cout << attr.get<std::string>() << " ";
        }
    }
    std::cout << std::endl;
*/
