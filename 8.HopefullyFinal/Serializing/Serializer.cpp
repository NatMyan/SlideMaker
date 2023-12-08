#include "Serializer.hpp"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>

void Serializer::exec(std::shared_ptr<Document> doc, JSONDocument& jsonDoc) {
    QJsonObject docObj;
    QJsonObject slideObj;
    QJsonObject itemObj;
    QJsonArray itemArr;
    QJsonArray attrArr;

    for (auto slide : doc) {
        slideObj["topItem"] = itemArr;
        itemObj["Attributes"] = attrArr;
        ///TODO: write the proper structure
    }

    jsonDoc(docObj);
}