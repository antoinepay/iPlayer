//
// Created by Antoine Payan on 27/10/2017.
//

#ifndef IPLAYER_REMOVEDUPLICATESCOMMAND_H
#define IPLAYER_REMOVEDUPLICATESCOMMAND_H


#include "../Command/Command.h"

class RemoveDuplicatesCommand : public Command {
public:
    RemoveDuplicatesCommand(Receiver *receiver, string parameter) : Command(receiver, parameter) {}

    string execute();
};


#endif
