//
// Created by Antoine Payan on 27/10/2017.
//

#ifndef IPLAYER_SHOWPLAYLISTCOMMAND_H
#define IPLAYER_SHOWPLAYLISTCOMMAND_H


#include "../Command/Command.h"

class ShowPlaylistCommand : public Command {
public:
    ShowPlaylistCommand(Receiver *receiver, string parameter) : Command(receiver, parameter) {}

    string execute();
};


#endif
