#ifndef I_SERIALIZER_HPP
#define I_SERIALIZER_HPP

#include "../Data/Document.hpp"

class ISerializer {
    public:
        virtual ~ISerializer() = default;
        virtual void relocateInfo() = 0;
};

#endif // I_SERIALIZER_HPP