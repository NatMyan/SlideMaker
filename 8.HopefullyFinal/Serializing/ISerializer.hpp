#ifndef I_SERIALIZER_HPP
#define I_SERIALIZER_HPP

#include "JSONDocument.hpp"
#include "../Data/Document.hpp"

///TODO: keep it here or not ?
class ISerializer {
    public:
        virtual void exec() = 0; //TK: Why it is called exec, may be save?
};

#endif // I_SERIALIZER_HPP