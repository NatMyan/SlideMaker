#ifndef JSON_DESERIALIZERR_HPP
#define JSON_DESERIALIZERR_HPP

#include "ISerializer.hpp"
#include "JSONDocument.hpp"

#include <memory>

class JsonDeserializer : public ISerializer {
    public:
        JsonDeserializer(std::shared_ptr<Document> doc, JSONDocument& jsonDoc);
        void relocateInfo();
    
    private:
        std::shared_ptr<Document> doc_;
        JSONDocument jsonDoc_;
};

#endif // JSON_DESERIALIZERR_HPP