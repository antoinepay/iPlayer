//
// Created by Antoine Payan on 27/10/2017.
//

#ifndef IPLAYER_PREVIOUSCOMMAND_H
#define IPLAYER_PREVIOUSCOMMAND_H


#include "../Command/Command.h"

class PreviousCommand : public Command {
public:
    PreviousCommand(Receiver *receiver, string parameter) : Command(receiver, parameter) {}

    string execute();
};


#endif
