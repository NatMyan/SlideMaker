#include "SaveCommand.hpp"
#include "../../Application.hpp"
#include "../../Serializing/Serializer.hpp"

#include <fstream>

SaveCommand::SaveCommand(const Map& info) :
    infoMap_(info)
{}

void SaveCommand::execute() {
    auto app = Application::getApplication();
    auto doc = app->getDocument();
    std::shared_ptr<Serializer> serializer = std::make_shared<Serializer>();
    auto fileName = defs::toStr(infoMap_["-file"]);
    JSONDocument jsonDoc;
    serializer->exec(doc, jsonDoc);
    QByteArray buffer = jsonDoc.getQJson().toJSON();

    std::ofstream file(fileName, std::ios::out | std::ios::binary);
    if (file.is_open()) {
        file.write(buffer.data(), buffer.size());
        file.close();
    }
}