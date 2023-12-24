#include "LoadCommand.hpp"
#include "../../Application.hpp"
#include "../../Serializing/JsonDeserializer.hpp"

#include <fstream>

LoadCommand::LoadCommand(const Map& info) :
    infoMap_(info)
{}

void LoadCommand::execute() {
    auto app = Application::getApplication();
    auto doc = app->getDocument();
    auto fileName = defs::toStr(infoMap_["-file"]);
    JSONDocument jsonDoc; 
    /// TODO: what does it^ get?
    std::shared_ptr<JsonDeserializer> deserializer = std::make_shared<JsonDeserializer>(doc, jsonDoc);

    std::ifstream file(fileName, std::ios::in | std::ios::binary);
    if (file.is_open()) {
        auto size = takeFileSize(file);

        std::vector<char> buffer(size);
        if (file.read(buffer.data(), size)) {
            jsonDoc.getQJson().fromJson(QByteArray(buffer.data(), size));
            deserializer->relocateInfo();
        }
        file.close();
    }
}

std::streamsize LoadCommand::takeFileSize(std::ifstream& file) {
    file.seekg(0, std::ios::end);
    std::streamsize size = file.tellg(); // Get the file's size
    file.seekg(0, std::ios::beg);
    return size;
}