#include "SaveCommand.hpp"
#include "../../Application.hpp"
#include "../../Serializing/JsonSerializer.hpp"
#include "../../Serializing/JSONDocument.hpp"

#include <fstream>

namespace cli {

SaveCommand::SaveCommand(const Map& info) :
    infoMap_(info)
{}

void SaveCommand::execute() {
    auto app = app::Application::getApplication();
    auto doc = app->getDocument();

    JSONDocument jsonDoc;
    std::shared_ptr<JsonSerializer> serializer = std::make_shared<JsonSerializer>(doc, jsonDoc);

    std::string fileName;
    try { fileName = defs::toStr(infoMap_["-file"]); }
    catch (const std::exception& e) { throw InvalidFileException("File name not found: " + fileName); }

    serializer->save();
    QByteArray buffer = jsonDoc.getQJson().toJson();

    std::ofstream file(fileName, std::ios::out | std::ios::binary);
    if (file.is_open()) {
        file.write(buffer.data(), buffer.size());
        file.close();
    }
    else { throw InvalidFileException("File failed to open: " + fileName); }
}

}