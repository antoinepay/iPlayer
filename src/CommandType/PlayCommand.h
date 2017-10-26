//
// Created by Antoine Payan on 26/10/2017.
//

#ifndef IPLAYER_PLAYCOMMAND_H
#define IPLAYER_PLAYCOMMAND_H

#include "../Command/Command.h"

class PlayCommand : public Command {
public:
    PlayCommand(Receiver *receiver, string parameter) : Command(receiver, parameter) {}

    string execute();
};


#endif
