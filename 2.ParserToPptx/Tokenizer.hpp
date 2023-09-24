#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <istream>
#include <string>

class Tokenizer {
    public: 
        std::istream& takeToken(std::istream& input);
        std::string getToken();

    private:
        std::string token_ = "";
};

#endif // TOKENIZER_HPP