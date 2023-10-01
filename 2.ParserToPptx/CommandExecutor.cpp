#include "CommandExecutor.hpp"

int CommandExecutor::id_ = 0;
std::vector<std::tuple<ID, std::map<std::string, ArgumentType> > > CommandExecutor::itemStorage_;