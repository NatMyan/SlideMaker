#include "SaveCommand.hpp"
#include "../../Application.hpp"
#include "../../Serializing/JsonSerializer.hpp"
#include "../../Serializing/JSONDocument.hpp"

#include <fstream>

SaveCommand::SaveCommand(const Map& info) :
    infoMap_(info)
{}

void SaveCommand::execute() {
    auto app = Application::getApplication();
    auto doc = app->getDocument();
    JSONDocument jsonDoc;
    std::shared_ptr<ISerializer> serializer = std::make_shared<JsonSerializer>(doc, jsonDoc);
    auto fileName = defs::toStr(infoMap_["-file"]);
    serializer->relocateInfo();
    QByteArray buffer = jsonDoc.getQJson().toJson();

    std::ofstream file(fileName, std::ios::out | std::ios::binary);
    if (file.is_open()) {
        file.write(buffer.data(), buffer.size());
        file.close();
    }
}