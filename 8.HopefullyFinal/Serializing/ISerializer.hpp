#ifndef I_SERIALIZER_HPP
#define I_SERIALIZER_HPP

#include "JSONDocument.hpp"
#include "../Data/Document.hpp"

///TODO: keep it here or not ?
class ISerializer {
    public:
        virtual void exec() = 0;
};

#endif // I_SERIALIZER_HPP