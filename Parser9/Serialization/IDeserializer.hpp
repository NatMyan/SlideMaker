#ifndef I_DESERIALIZER_HPP
#define I_DESERIALIZER_HPP

#include "../Data/Document.hpp"

namespace srl {

class IDeserializer {
    public:
        virtual ~IDeserializer() = default;
        virtual void load() = 0;
};

}

#endif // I_DESERIALIZER_HPP