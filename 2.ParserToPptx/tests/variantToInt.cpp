#include <iostream>
#include <map>
#include <variant>

using CommandNameType = std::string;
using ArgumentType = std::variant<std::string, int, double>;
using CommandType = std::tuple<int, CommandNameType, std::map<std::string, ArgumentType> >;

int main() {
    CommandType myVariant; 
    std::get<2>(myVariant)["-id"] = 48;
    std::get<0>(myVariant) = 0;
    int intValue = std::get<int>(std::get<2>(myVariant)["-id"]);
    std::cout << intValue << std::endl;

    return 0;
}
