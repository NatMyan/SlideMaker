#ifndef SHAPE_REGISTRY_HPP
#define SHAPE_REGISTRY_HPP

#include <string>

using ShapeNameType = std::string;

class ShapeRegistry {
    public:
        ShapeRegistry();
        
    public:
        ShapeNameType findShape (const std::string& shapeName); // commandName is from takeToken

    private:
        std::vector<ShapeNameType> shapeSpec_;
};


#endif // SHAPE_REGISTRY_HPP