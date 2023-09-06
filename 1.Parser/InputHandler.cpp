#include "InputHandler.hpp"

template <typename InputType>
InputHandler<InputType>::InputHandler() {
    std::stringstream ssInput;
    std::cin >> input;

    ssInput << input;
}

template <typename InputType> // typename StreamType,
std::stringstream InputHandler<InputType>::getInput () {
    return input;
}

template <typename InputType>
void setInput (const InputType& input) {
    this->input = input;
}