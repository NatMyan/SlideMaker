#include "SaveCommand.hpp"

SaveCommand::SaveCommand(const Map& info) :
    infoMap_(info)
{}

void SaveCommand::execute() {
    auto doc = Application::getDocument();
    std::shared_ptr<Serializer> serializer;
    JSONDocument jsonDoc;
    serializer->save(doc, jsonDoc);
    QByteArray buffer = jsonDoc.toJSON();
    std::ofstream file(...);
    if (file.is_open()) {
        ///TODO: write to file
    }
}