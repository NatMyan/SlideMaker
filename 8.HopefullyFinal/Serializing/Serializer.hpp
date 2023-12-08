#ifndef SERIALIZERR_HPP
#define SERIALIZERR_HPP

#include "ISerializer.hpp"

#include <memory>

class Serializer : public ISerializer {
    public:
        void exec(std::shared_ptr<Document> doc, JSONDocument jsonDoc);
};

#endif // SERIALIZERR_HPP