#include "event_handlers.hh"

//add the handler to the vector
void EventManager::registerEventHandler(IEventHandler* handler) {
    listeners.push_back(handler);
}

//returnt the handler at the given index
IEventHandler* EventManager::getEventHandlerAt(int indx) {
    return listeners[indx];
}

//calls the evnt for the registered objects
void EventManager::notifyEvent(Event* e) {
    //loop around the handlers
    for (int i = 0; i < (int)listeners.size(); i++) {
        //get the handler on the current iteration
        IEventHandler* listener = getEventHandlerAt(i);

        //if it exists, call the event on it
        if (listener != nullptr)
            listener->call(e);
    }
}