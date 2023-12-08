#include "Deerializer.hpp"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>

void Deerializer::exec(std::shared_ptr<Document> doc, JSONDocument& jsonDoc) {
    for (const QJsonValue& attributeValue : attributesArray) {
        QJsonObject attributeObject = attributeValue.toObject();
        QString lcolor = attributeObject["lcolor"].toString();
        QString fcolor = attributeObject["fcolor"].toString();
    }
    doc->getSlide()->getItem()->setPair("lcolor", lcolor);
    ///TODO: continue
}


/*QJsonObject docObj;
    QJsonObject slideObj;
    QJsonObject itemObj;
    QJsonArray itemArr;
    QJsonArray attrArr;

    for (auto slide : doc) {
        slideObj["topItem"] = itemArr;
        itemObj["Attributes"] = attrArr;
        ///TODO: write the proper structure
    }

    jsonDoc(docObj);*/