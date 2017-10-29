//
// Created by Antoine Payan on 27/10/2017.
//

#ifndef IPLAYER_SHOWTRACKCOMMAND_H
#define IPLAYER_SHOWTRACKCOMMAND_H


#include "../Command/Command.h"

class ShowTrackCommand : public Command {
public:
    ShowTrackCommand(Receiver *receiver, string parameter) : Command(receiver, parameter) {}

    string execute();
};


#endif
