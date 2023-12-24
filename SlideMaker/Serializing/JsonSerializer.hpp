#ifndef JSON_SERIALIZERR_HPP
#define JSON_SERIALIZERR_HPP

#include "ISerializer.hpp"
#include "JSONDocument.hpp"

#include <memory>

class JsonSerializer : public ISerializer {
    public:
        JsonSerializer(std::shared_ptr<Document> doc, JSONDocument& jsonDoc);
        void relocateInfo();
    
    private:
        std::shared_ptr<Document> doc_;
        JSONDocument jsonDoc_;
};

#endif // JSON_SERIALIZERR_HPP