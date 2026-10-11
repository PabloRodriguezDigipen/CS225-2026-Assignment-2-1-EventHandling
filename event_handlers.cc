#include "event_handlers.hh"

void EventManager::registerEventHandler(IEventHandler* handler) {
    handlers.push_back(handler);
}

IEventHandler* EventManager::getEventHandlerAt(int indx) {
    return handlers[indx];
}

void EventManager::notifyEvent(Event* e) {
    for (int i = 0; i < (int)handlers.size(); i++) {
        IEventHandler* handler = getEventHandlerAt(i);

        if (handler != nullptr) {
            handler->call(e);
        }
    }
}