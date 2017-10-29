//
// Created by Antoine Payan on 27/10/2017.
//

#ifndef IPLAYER_REMOVETRACKCOMMAND_H
#define IPLAYER_REMOVETRACKCOMMAND_H


#include "../Command/Command.h"

class RemoveTrackCommand : public Command {
public:
    RemoveTrackCommand(Receiver *receiver, string parameter) : Command(receiver, parameter) {}

    string execute();
};


#endif
