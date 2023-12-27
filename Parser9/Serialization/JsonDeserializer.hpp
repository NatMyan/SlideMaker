#ifndef JSON_DESERIALIZERR_HPP
#define JSON_DESERIALIZERR_HPP

#include "IDeserializer.hpp"
#include "JSONDocument.hpp"
#include "../Data/Document.hpp"

#include <memory>

namespace srl {

using Document = dat::Document;

class JsonDeserializer : public IDeserializer {
    public:
        JsonDeserializer(std::shared_ptr<Document> doc, JSONDocument& jsonDoc);
        void load();
    
    private:
        std::shared_ptr<Document> doc_;
        JSONDocument jsonDoc_;
};

}

#endif // JSON_DESERIALIZERR_HPP