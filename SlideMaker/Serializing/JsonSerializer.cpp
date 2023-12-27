#include "JsonSerializer.hpp"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>

JsonSerializer::JsonSerializer(std::shared_ptr<Document> doc, JSONDocument& jsonDoc) :
    jsonDoc_(jsonDoc),
    doc_(doc)
{}

void JsonSerializer::relocateInfo() {
    QJsonDocument jDoc;

    QJsonObject document;
    document["format"] = QString::fromUtf8(doc_->getFormatSize().first);
    document["orientation"] = QString::fromUtf8(doc_->getOrientation());

    QJsonArray groupArray;

    QJsonObject groupObject;
    for (auto it = doc_->begin(); it != doc_->end(); ++it) {
        // groupObject["type"] = QString::fromUtf8((*it)->getItemGroup()->getType().c_str());
        QJsonObject bboxObject;
        bboxObject["l"] = (*it)->getItemGroup()->getBoundingBox().first.first;
        bboxObject["t"] = (*it)->getItemGroup()->getBoundingBox().first.second;
        bboxObject["r"] = (*it)->getItemGroup()->getBoundingBox().second.first;
        bboxObject["b"] = (*it)->getItemGroup()->getBoundingBox().second.second;
        groupObject["bbox"] = bboxObject;

        QJsonObject attrObject;
        for (auto attr : (*it)->getItemGroup()->getAttributes()) {
            attrObject[QString::fromUtf8(attr.first.c_str())] = QString::fromUtf8(defs::toStr(attr.second));
        }
        groupObject["attributes"] = attrObject;
        auto group = (*it)->getItemGroup();

        QJsonArray itemArray;
        for (auto iter = group->begin(); iter != group->end(); ++iter) {
            QJsonObject itemObject;
            itemObject["type"] = QString::fromUtf8((*iter)->getType());
            itemObject["-id"] = (*iter)->getID();

            QJsonObject bboxObject2;
            bboxObject2["l"] = (*iter)->getBoundingBox().first.first;
            bboxObject2["t"] = (*iter)->getBoundingBox().first.second;
            bboxObject2["r"] = (*iter)->getBoundingBox().second.first;
            bboxObject2["b"] = (*iter)->getBoundingBox().second.second;
            itemObject["bbox"] = bboxObject2;

            QJsonObject attrObject2;
            for (auto attr : (*iter)->getAttributes()) {
                attrObject2[QString::fromUtf8(attr.first.c_str())] = QString::fromUtf8(defs::toStr(attr.second));
            }
            itemObject["attributes"] = attrObject2;

            itemArray.append(itemObject);
        }
        groupObject["items"] = itemArray;

        groupArray.append(groupObject);
    }

    document["slides"] = groupArray;

    jDoc.setObject(document);
    jsonDoc_.setQJson(jDoc);
}
