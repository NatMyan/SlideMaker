#ifndef LOAD_ACTION_HPP
#define LOAD_ACTION_HPP

#include "Serializer.hpp"
#include "../Data/Document.hpp"

#include <fstream>
#include <istream>
#include <memory>

class LoadAction : public Serializer {
    public:
        LoadAction(std::string fileName, std::ifstream& fileToLoad, std::shared_ptr<Document> nDoc, Idx idx);
        //LoadAction l(nDoc, idx);
        void execute();
    
    private:
        Idx idx_;
        std::shared_ptr<Document> nDoc_;
        std::ifstream& fileToLoad_;
        std::string fileName_;

};

#endif // LOAD_ACTION_HPP