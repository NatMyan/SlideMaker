#include "JsonSerializer.hpp"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>

namespace srl {

using Document = dat::Document;
    
JsonSerializer::JsonSerializer(std::shared_ptr<Document> doc, JSONDocument& jsonDoc) :
    jsonDoc_(jsonDoc),
    doc_(doc)
{}

void JsonSerializer::save() {
    QJsonObject document;
    document["format"] = QString::fromUtf8(doc_->getFormatSize().first);
    document["orientation"] = QString::fromUtf8(doc_->getOrientation());
    document["slides"] = takeGroupArray(doc_);

    QJsonDocument jDoc;
    jDoc.setObject(document);
    jsonDoc_.setQJson(jDoc);
}


QJsonObject JsonSerializer::takeBbox(std::shared_ptr<dat::IItem> item) {
    QJsonObject bboxObject;
    bboxObject["l"] = (item)->getBoundingBox().first.first;
    bboxObject["t"] = (item)->getBoundingBox().first.second;
    bboxObject["r"] = (item)->getBoundingBox().second.first;
    bboxObject["b"] = (item)->getBoundingBox().second.second;
    return bboxObject;
}

QJsonArray JsonSerializer::takeItemArray(std::shared_ptr<dat::ItemGroup> group) {
    QJsonArray itemArray;
    for (auto item_it = group->begin(); item_it != group->end(); ++item_it) {
        QJsonObject itemObject;
        itemObject["type"] = QString::fromUtf8((*item_it)->getType());
        itemObject["-id"] = (*item_it)->getID();

        QJsonObject bboxObject2 = takeBbox(*item_it);
        itemObject["bbox"] = bboxObject2;

        QJsonObject attrObject2;
        for (auto attr : (*item_it)->getAttributes()) {
            attrObject2[QString::fromUtf8(attr.first.c_str())] = QString::fromUtf8(defs::toStr(attr.second));
        }
        itemObject["attributes"] = attrObject2;

        itemArray.append(itemObject);
    }
    return itemArray;
}
 
QJsonArray JsonSerializer::takeGroupArray(std::shared_ptr<Document> doc) {
    QJsonArray groupArray;
    for (auto slide_it = doc->begin(); slide_it != doc->end(); ++slide_it) {
        // groupObject["type"] = QString::fromUtf8((*it)->getItemGroup()->getType().c_str());
        QJsonObject groupObject;
        QJsonObject bboxObject = takeBbox((*slide_it)->getItemGroup());
        groupObject["bbox"] = bboxObject;

        QJsonObject attrObject;
        for (auto attr : (*slide_it)->getItemGroup()->getAttributes()) {
            attrObject[QString::fromUtf8(attr.first.c_str())] = QString::fromUtf8(defs::toStr(attr.second));
        }
        groupObject["attributes"] = attrObject;
        auto group = (*slide_it)->getItemGroup();
        groupObject["items"] = takeItemArray(group);

        groupArray.append(groupObject);
    }
    return groupArray;
} 

}
