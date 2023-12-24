#ifndef TOKENIZERR_HPP
#define TOKENIZERR_HPP

#include <istream>
#include <string>

class Tokenizer {
    public:
        Tokenizer(const char& endOfLineToken);

    public: 
        std::string takeToken (std::istream& iss);
        // std::string getNextToken (std::istream& iss, const char& endOfLineToken);
    
    private:
        const char& endOfLineToken_;
};

#endif // TOKENIZERR_HPP