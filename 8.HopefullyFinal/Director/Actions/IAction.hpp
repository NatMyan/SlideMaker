#ifndef I_ACTION_HPP
#define I_ACTION_HPP

class IAction {
    public:
        //TK: You need only one methiod here, and there no need to repeat word 'Action'
        virtual std::shared_ptr<IAction> do() = 0; 
        //virtual void doAction() = 0;
        //virtual std::shared_ptr<IAction> createReverseAction() = 0; 
};

#endif // I_ACTION_HPP