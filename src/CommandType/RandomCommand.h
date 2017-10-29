//
// Created by Antoine Payan on 27/10/2017.
//

#ifndef IPLAYER_RANDOMCOMMAND_H
#define IPLAYER_RANDOMCOMMAND_H


#include "../Command/Command.h"

class RandomCommand : public Command {
public:
    RandomCommand(Receiver *receiver, string parameter) : Command(receiver, parameter) {}

    string execute();
};


#endif
