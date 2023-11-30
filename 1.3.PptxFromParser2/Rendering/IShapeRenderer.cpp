#include "IShapeRenderer.hpp"

#include <QString>
#include <QHash>

IShapeRenderer::IShapeRenderer(Idx idx, std::shared_ptr<Item> itemPtr) :
    itemPtr_(itemPtr),
    idx_(idx)     
{}

void IShapeRenderer::print(std::ostream& stream) {
    stream << idx_ << ": " << itemPtr_->getID() << " " << itemPtr_->getType() << " ";
    auto pos = itemPtr_->getPosition();
    NumberType l = pos.first.first;
    NumberType t = pos.first.second;
    NumberType r = pos.second.first;
    NumberType b = pos.second.second;
    stream << "-l " << l << "-t " << t << "-r " << r << "-b " << b << " ";
    auto attrs = itemPtr_->getAttributes();
    for (const auto& attr : attrs) {
        stream << attrs.getKey(attr);
        if (std::is_same_v<decltype(attr), int> && attr.holdsAlternative<int>()) {
            stream << attr.get<int>() << " ";
        }
        else if (std::is_same_v<decltype(attr), double> && attr.holdsAlternative<double>()) {
            stream << attr.get<double>() << " ";
        }
        else if (std::is_same_v<decltype(attr), std::string> && attr.holdsAlternative<std::string>()) {
            stream << attr.get<std::string>() << " ";
        }
    }
    stream << std::endl;
}

// QColor(int r, int g, int b, int a = 255)
///TODO: bad design, change it someday
Qt::GlobalColor IShapeRenderer::stringToGlobalColor(const QString& colorName) {
    static const QHash<QString, Qt::GlobalColor> colorMap = {
        {"red", Qt::red},
        {"green", Qt::green},
        {"blue", Qt::blue},
        {"yellow", Qt::yellow},
        {"darkYellow", Qt::darkYellow},
        {"darkBlue", Qt::darkBlue},
        {"darkCyan", Qt::darkCyan}
    };
    return colorMap.value(colorName, Qt::black); // Default to black if the color is not found
}