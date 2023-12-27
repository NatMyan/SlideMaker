#ifndef I_SERIALIZER_HPP
#define I_SERIALIZER_HPP

#include "../Data/Document.hpp"

namespace srl {
 
class ISerializer {
    public:
        virtual ~ISerializer() = default;
        virtual void save() = 0;
};

}

#endif // I_SERIALIZER_HPP