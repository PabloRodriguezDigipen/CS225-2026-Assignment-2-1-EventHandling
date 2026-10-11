#pragma once
#include "event.hh"
#include <vector>

//evnt handler interface
class IEventHandler {
    public:
    //call function to be inherited
    virtual void call(Event *event) = 0;
    //need a virtual destructor to be inherited
    virtual ~IEventHandler() = default;
};

//event handler class
template<typename TObject, typename TEvent>
class EventHandler : public IEventHandler {
private:
    //EventType function pointer
    typedef void (TObject::*EventType)(TEvent*);

    //object using the event
    TObject* object;
    //event subscribed to
    EventType method;

public:
    //constructor of the handler
    EventHandler(TObject* obj, EventType method) : object(obj), method(method) {}

    //calls the events of the objects
    void call(Event* event) override {
        //cast the event to the specific event the object needs
        TEvent* specific_event = dynamic_cast<TEvent*>(event);
        
        //if it exists, run the event
        if (specific_event != nullptr)
            (object->*method)(specific_event);
    }
};

//event manager class
class EventManager {
private:
//vector of event handler interfaces, since event handlers are templated
    std::vector<IEventHandler*> listeners;

public:
    //registers an event handler in the vetor
    void registerEventHandler(IEventHandler* listener);
    //returns the handler on the given index
    IEventHandler* getEventHandlerAt(int indx);
    //calls the event for the registered handlers
    void notifyEvent(Event* e);
};