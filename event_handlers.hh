#pragma once
#include "event.hh"

class IEventHandler {
    public:
    virtual void call(Event *event) = 0;
    virtual ~IEventHandler() = default;
};

template<typename TObject, typename TEvent>
class EventHandler : public IEventHandler {
typedef void (TObject::*MethodType)(TEvent*);

    TObject* object;
    MethodType method;

public:
    EventHandler(TObject* obj, MethodType method) : object(obj), method(method) {}

    void call(Event* event) override {
        TEvent* specific_event = dynamic_cast<TEvent*>(event);

        if (specific_event != nullptr)
            (object->*method)(specific_event);
    }
};