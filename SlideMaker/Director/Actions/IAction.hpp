#ifndef I_ACTION_HPP
#define I_ACTION_HPP

#include <memory>

class IAction {
    public: 
        virtual ~IAction() = default;
        virtual std::shared_ptr<IAction> doAction() = 0;
        // virtual std::shared_ptr<IAction> createReverseAction() = 0; 
};

#endif // I_ACTION_HPP