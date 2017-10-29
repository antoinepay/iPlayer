//
// Created by Antoine Payan on 27/10/2017.
//

#ifndef IPLAYER_PAUSECOMMAND_H
#define IPLAYER_PAUSECOMMAND_H

#include "../Command/Command.h"

class PauseCommand : public Command {
public:
    PauseCommand(Receiver *receiver, string parameter) : Command(receiver, parameter) {}

    string execute();
};


#endif
