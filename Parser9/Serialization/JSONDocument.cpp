#include "JSONDocument.hpp"

namespace srl {

QJsonDocument JSONDocument::getQJson() {
    return jsonDoc_;
}

void JSONDocument::setQJson(QJsonDocument jsonDoc) {
    jsonDoc_ = jsonDoc;
}

}