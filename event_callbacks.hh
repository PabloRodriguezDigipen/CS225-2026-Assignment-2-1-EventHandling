#pragma once
#include "event.hh"
#include <vector>

typedef void (*CallbackFunction)(void*, Event*);

class EventListener {
    public:
    void* contextObject;
    CallbackFunction callbackFunction;
};

class EventDispatcher {
    private:
    std::vector<EventListener> listeners;
    public:
    void subscribe(void* contextObject, CallbackFunction callbackFunction);
    EventListener* getListenerAt(int indx);
    void dispatchEvent(Event* e);
};