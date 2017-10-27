//
// Created by Antoine Payan on 27/10/2017.
//

#ifndef IPLAYER_CREATEPLAYLISTCOMMAND_H
#define IPLAYER_CREATEPLAYLISTCOMMAND_H

#include "../Command/Command.h"

class CreatePlaylistCommand : public Command {
public:

    CreatePlaylistCommand(Receiver *receiver, string parameter) : Command(receiver, parameter) {}

    string execute();
};


#endif
