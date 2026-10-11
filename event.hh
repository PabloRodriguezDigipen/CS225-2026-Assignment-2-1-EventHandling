#pragma once

//event class
class Event {
public:
    //need a virtual destructor to be inherited
    virtual ~Event() = default;
};