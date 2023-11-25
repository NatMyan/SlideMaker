#include "DisplayCommand.hpp"

#include <iostream>

///TODO: I hate this
void DisplayCommand::execute(CommandType parsedCmd, std::shared_ptr<Document> doc, std::shared_ptr<Director> dir) {
    MapPair<Key, Value> pairs = parsedCmd.get<1>();
    if (pairs.find("-idx") != pairs.end()) {
        auto idx = pairs["-idx"].get<Idx>();
        auto slide = doc->getSlide(idx).lock();
        for (auto item : slide->getSlide()) {
            DisplayItemAction di(idx, item);
            di.execute();
        }
    }
    else if (pairs.find("-id") != pairs.end()) {
        auto id = pairs["-id"].get<ID>();
        auto slides = doc->getSlides(); 
        Idx idx = 0;
        for (auto slide : slides) {
            if (slide->getItem(id)) {
                auto item = slide->getItem(id);
                DisplayItemAction di(idx, item);
                di.execute();
                break;
            }
            ++idx;
        }
    }
    else {
        auto id = pairs["-id"].get<ID>();
        auto slides = doc->getSlides(); 
        Idx idx = 0;
        for (auto slide : slides) {
            if (slide->getItem(id)) {
                auto item = slide->getItem(id);
                DisplayItemAction di(idx, item);
                di.execute();
            }
            ++idx;
        }
    }
}

/*std::cout << "slide" << " " << idx << std::endl;
    // if (!slide->getSlide().empty()) {
        for (const auto& item : slide->getSlide()) {
            std::cout << item->getID() << " " << item->getType() << " ";
            auto pos = item->getPosition();
            NumberType l = pos.first.first;
            NumberType t = pos.first.second;
            NumberType r = pos.second.first;
            NumberType b = pos.second.second;
            std::cout << "-l " << l << "-t " << t << "-r " << r << "-b " << b << " ";

            auto attrs = item->getAttributes();
            for (const auto& attr : attrs) {
                std::cout << attrs.getKey(attr);
                if (std::is_same_v<decltype(attr), int> && attr.holdsAlternative<int>()) {
                    std::cout << attr.get<int>() << " ";
                }
                else if (std::is_same_v<decltype(attr), double> && attr.holdsAlternative<double>()) {
                    std::cout << attr.get<double>() << " ";
                }
                else if (std::is_same_v<decltype(attr), std::string> && attr.holdsAlternative<std::string>()) {
                    std::cout << attr.get<std::string>() << " ";
                }
            }
        }
        std::cout << std::endl;
        ++idx;*/
    // }
    /*else {
        std::cout << "No items here" << std::endl;
    }*/