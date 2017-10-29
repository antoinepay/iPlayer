//
// Created by Antoine Payan on 27/10/2017.
//

#ifndef IPLAYER_NEXTCOMMAND_H
#define IPLAYER_NEXTCOMMAND_H


#include "../Command/Command.h"

class NextCommand : public Command {
public:
    NextCommand(Receiver *receiver, string parameter) : Command(receiver, parameter) {}

    string execute();
};


#endif
