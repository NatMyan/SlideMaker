#include "JSONDocument.hpp"

QJsonDocument JSONDocument::getQJson() {
    return jsonDoc_;
}

void JSONDocument::setQJson(QJsonDocument jsonDoc) {
    jsonDoc_ = jsonDoc;
}