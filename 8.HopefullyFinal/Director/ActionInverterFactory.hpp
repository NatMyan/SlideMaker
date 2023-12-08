#ifndef ACTION_INVERTER_FACTORY_HPP
#define ACTION_INVERTER_FACTORY_HPP

#include "IAction.hpp"
#include "UndoRedoActionContainer.hpp"
#include "AddItemAction.hpp"
#include "AddSlideAction.hpp"
#include "RemoveItemAction.hpp"
#include "RemoveSlideAction.hpp"
#include "ChangeItemAction.hpp"
#include "ChangeSlideAction.hpp"

class ActionInverterFactory {
    public:
        std::shared_ptr<IAction> createReverseAction(std::shared_ptr<IAction> action);
};

#endif // ACTION_INVERTER_FACTORY_HPP