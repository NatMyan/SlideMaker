#include "LoadCommand.hpp"

LoadCommand::LoadCommand(const Map& info) :
    info_(info)
{}

void LoadCommand::execute() {
    ///TODO: change order of lines
    auto doc = Application::getDocument();
    std::shared_ptr<Deserializer> deserializer;
    JSONDocument jsonDoc;
    deserializer->load(doc, jsonDoc);
    QByteArray buffer = jsonDoc.fromJSON();
    // std::ifstream file(...);
    // if (file.is_open()) {
        ///TODO: read from file
    // }
}