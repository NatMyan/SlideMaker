#ifndef JSON_DOCUMENT_HPP
#define JSON_DOCUMENT_HPP

#include <QJsonDocument>

namespace srl {

class JSONDocument {
    public:
        JSONDocument() = default;
        QJsonDocument getQJson();
        void setQJson(QJsonDocument jsonDoc);
    
    private:
        QJsonDocument jsonDoc_;
};

}

#endif // JSON_DOCUMENT_HPP