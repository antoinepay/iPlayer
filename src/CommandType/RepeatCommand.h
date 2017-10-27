//
// Created by Antoine Payan on 27/10/2017.
//

#ifndef IPLAYER_REPEATCOMMAND_H
#define IPLAYER_REPEATCOMMAND_H


#include "../Command/Command.h"

class RepeatCommand : public Command {
public:
    RepeatCommand(Receiver *receiver, string parameter) : Command(receiver, parameter) {}

    string execute();
};


#endif
