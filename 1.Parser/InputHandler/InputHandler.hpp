#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <sstream>

template <typename InputType>
InputType input(); 


template <typename InputType>  // probably a useless class
class InputHandler {
    public:        
        InputHandler (InputType inputValue);
        ~InputHandler();

    public:
        std::stringstream getInput();
        void setInput (const InputType& input);
    
    private:
        std::stringstream ssInput;
};

#endif // INPUT_HANDLER_HPP