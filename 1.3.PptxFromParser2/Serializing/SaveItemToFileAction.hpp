#ifndef SAVE_ACTION_HPP
#define SAVE_ACTION_HPP

#include "Serializer.hpp"
#include "../Data/Item.hpp"

#include <fstream>
#include <ostream>

class SaveItemToFileAction : public Serializer {
    public:
        SaveItemToFileAction(std::string fileName, std::ofstream& fileToSave, Idx idx, std::shared_ptr<Item> item);
        void execute();

    private:
        Idx idx_;
        std::shared_ptr<Item> item_;
        std::ofstream& fileToSave_;
        std::string fileName_;
};

#endif // SAVE_ACTION_HPP