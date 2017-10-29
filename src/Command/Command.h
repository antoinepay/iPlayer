//
// Created by Antoine Payan on 26/10/2017.
//

#ifndef IPLAYER_COMMAND_H
#define IPLAYER_COMMAND_H

#include "Receiver.h"

class Command {

protected:
    Receiver *receiver;
    string parameter;

public:
    Command(Receiver *r, string parameter) : receiver(r), parameter(parameter)  {}
    virtual string execute() = 0;
};


#endif
