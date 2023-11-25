#include "ListAction.hpp"

#include <iostream>

ListAction::ListAction (Idx idx, Type type, ID id) :
    idx_(idx),
    type_(type),
    id_(id)
{}

/// TODO: std::cout ?
void ListAction::execute() {
    std::cout << idx_ << " " << id_ << " " << type_ << std::endl;
}