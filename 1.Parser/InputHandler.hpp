#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <sstream>

template <typename InputType> // typename StreamType,
class InputHandler {
    public:        
        InputHandler();
        ~InputHandler();

    public:
        std::stringstream getInput ();
        void setInput(const InputType& input);
    
    private:
        InputType input;
};

#endif // INPUT_HANDLER_HPP