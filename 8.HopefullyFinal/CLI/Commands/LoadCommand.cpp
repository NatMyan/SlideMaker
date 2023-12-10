#include "LoadCommand.hpp"
#include "../../Application.hpp"
#include "../../Serializing/Deserializer.hpp"

#include <fstream>

LoadCommand::LoadCommand(const Map& info) :
    infoMap_(info)
{}

void LoadCommand::execute() {
    auto doc = Application::getDocument();
    auto fileName = defs::toStr(infoMap_["-file"]);
    std::shared_ptr<Deserializer> deserializer = std::make_shared<Deserializer>();
    JSONDocument jsonDoc;

    std::ifstream file(fileName, std::ios::in | std::ios::binary);
    if (file.is_open()) {
        auto size = takeFileSize(file);

        std::vector<char> buffer(size);
        if (file.read(buffer.data(), size)) {
            jsonDoc.getQJson().fromJSON(QByteArray(buffer.data(), size));
            deserializer->exec(doc, jsonDoc);
        }
        file.close();
    }
}

std::streamsize LoadCommand::takeFileSize(std::ifstream& file) {
    file.seekg(0, std::ios::end);
    std::streamsize size = file.tellg(); // Get the file size
    file.seekg(0, std::ios::beg);
    return size;
}