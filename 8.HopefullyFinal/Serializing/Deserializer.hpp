#ifndef DESERIALIZERR_HPP
#define DESERIALIZERR_HPP

#include "ISerializer.hpp"

#include <memory>

class Deserializer : public ISerializer {
    public:
        void exec(std::shared_ptr<Document> doc, JSONDocument& jsonDoc);
};

#endif // DESERIALIZERR_HPP