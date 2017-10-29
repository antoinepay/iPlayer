//
// Created by Antoine Payan on 27/10/2017.
//

#ifndef IPLAYER_ADDTRACKCOMMAND_H
#define IPLAYER_ADDTRACKCOMMAND_H

#include "../Command/Command.h"

class AddTrackCommand : public Command {
public:

    AddTrackCommand(Receiver *receiver, string parameter) : Command(receiver, parameter) {}
    string execute();
};


#endif
