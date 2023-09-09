#include "InputHandler.hpp"

template <typename InputType>
InputType input() {
    InputType inputValue;
    if constexpr (std::is_same_v<InputType, std::string>) 
        std::getline(std::cin, inputValue); // Read whole line or smth
    else 
        std::cin >> inputValue; 

    return inputValue;
}

template <typename InputType>
InputHandler<InputType>::InputHandler (InputType inputValue) {
    ssInput << inputValue;
}

template <typename InputType> // typename StreamType,
std::stringstream InputHandler<InputType>::getInput () {
    return ssInput;
}

template <typename InputType>
void InputHandler<InputType>::setInput (const InputType& newInput) {
    std::stringstream().swap(ssIntput);
    ssInput << newInput;
}