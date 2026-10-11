#pragma once
#include "event.hh"
#include <vector>

//callback function pointer
typedef void (*CallbackFunction)(void*, Event*);

//event listener class
class EventListener {
public:
    //object acting to the event
    void* contextObject;
    //function pointer of the event
    CallbackFunction callbackFunction;
};

//event distpacher class
class EventDispatcher {
private:
    //vector of listeners
    std::vector<EventListener> listeners;
public:
    //to subscribe a listener to an event
    void subscribe(void* contextObject, CallbackFunction callbackFunction);
    //returns a listener on the given index position
    EventListener* getListenerAt(int indx);
    //sends the given event to the listeners
    void dispatchEvent(Event* e);
};