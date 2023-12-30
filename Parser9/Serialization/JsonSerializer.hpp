#ifndef JSON_SERIALIZERR_HPP
#define JSON_SERIALIZERR_HPP

#include "ISerializer.hpp"
#include "JSONDocument.hpp"
#include "../Data/Document.hpp"

#include <memory>

namespace srl {

using Document = dat::Document;

class JsonSerializer : public ISerializer {
    public:
        JsonSerializer(std::shared_ptr<Document> doc, JSONDocument& jsonDoc);
        void save();
    
    private:
        QJsonObject takeBbox(std::shared_ptr<dat::IItem> item);
        QJsonArray takeItemArray(std::shared_ptr<dat::ItemGroup> group);
        QJsonArray takeGroupArray(std::shared_ptr<dat::Document> doc); 
    
    private:
        std::shared_ptr<Document> doc_;
        JSONDocument jsonDoc_;
};

}

#endif // JSON_SERIALIZERR_HPP