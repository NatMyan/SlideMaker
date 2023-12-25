#ifndef TOKENIZERR_HPP
#define TOKENIZERR_HPP

#include <istream>
#include <string>

namespace cli {

class Tokenizer {
    public:
        Tokenizer(const char& endToken);

    public: 
        std::string takeToken (std::istream& iss);
    
    private:
        const char& endToken_;
};

}

#endif // TOKENIZERR_HPP