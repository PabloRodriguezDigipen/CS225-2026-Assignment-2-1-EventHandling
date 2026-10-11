#include "event_callbacks.hh"

//function to subscribe objects to events
void EventDispatcher::subscribe(void* contextObject, CallbackFunction callbackFunction) {
    //create a listener
    EventListener listener;
    //define the listener's parameters as the given object and event
    listener.contextObject = contextObject;
    listener.callbackFunction = callbackFunction;
    //add the listener to the listener vector
    listeners.push_back(listener);
}

//returns the listener on the given index
EventListener* EventDispatcher::getListenerAt(int indx) {
    return &listeners[indx];
}

//calls the event for all the subscribed objects
void EventDispatcher::dispatchEvent(Event* e) {
    //loop around the listeners
    for (int i = 0; i < (int)listeners.size(); i++) {
        //get the listener at the current iteration's index
        EventListener* listener = getListenerAt(i);
        //call the function for the event
        listener->callbackFunction(listener->contextObject, e);
    }
}