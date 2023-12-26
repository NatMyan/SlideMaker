#include "LoadCommand.hpp"
#include "../../Application.hpp"
#include "../../Serializing/JsonDeserializer.hpp"

#include <fstream>

namespace cli {

LoadCommand::LoadCommand(const Map& info) :
    infoMap_(info)
{}

void LoadCommand::execute() {
    auto app = app::Application::getApplication();
    auto doc = app->getDocument();

    JSONDocument jsonDoc; 
    std::shared_ptr<JsonDeserializer> deserializer = std::make_shared<JsonDeserializer>(doc, jsonDoc);

    std::string fileName;
    try { fileName = defs::toStr(infoMap_["-file"]); }
    catch (const std::exception& e) { throw InvalidFileException("File name not found: " + fileName); }

    std::ifstream file(fileName, std::ios::in | std::ios::binary);
    if (file.is_open()) {
        auto size = takeFileSize(file);
        std::vector<char> buffer(size);
        
        if (file.read(buffer.data(), size)) {
            jsonDoc.getQJson().fromJson(QByteArray(buffer.data(), size));
            deserializer->load();
        }
        file.close();
    }
    else { throw InvalidFileException("File failed to open: " + fileName); }
}

std::streamsize LoadCommand::takeFileSize(std::ifstream& file) {
    file.seekg(0, std::ios::end);
    std::streamsize size = file.tellg(); // Get the file's size
    file.seekg(0, std::ios::beg);
    return size;
}

}