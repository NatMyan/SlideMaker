#ifndef I_ACTION_HPP
#define I_ACTION_HPP

class IAction {
    public:
        virtual void doAction() = 0;
        virtual std::shared_ptr<IAction> createReverseAction() = 0; 
};

#endif // I_ACTION_HPP