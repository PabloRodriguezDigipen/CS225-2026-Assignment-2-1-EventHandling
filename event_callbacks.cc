#include "event_callbacks.hh"

void dummyCallback(void* userData, Event* evt) {}

void EventDispatcher::subscribe(void* contextObject, CallbackFunction callbackFunction) {
    EventListener listener;

    listener.contextObject = contextObject;
    listener.callbackFunction = callbackFunction;

    listeners.push_back(listener);
}

EventListener* EventDispatcher::getListenerAt(int indx) {
    return &listeners[indx];
}

void EventDispatcher::dispatchEvent(Event* e) {
    for (int i = 0; i < (int)listeners.size(); i++) {
        EventListener* listener = getListenerAt(i);

        if (listener != nullptr) {
            listener->callbackFunction(listener->contextObject, e);
        }
    }
}