//
// Created by Antoine Payan on 27/10/2017.
//

#ifndef IPLAYER_LOADPLAYLISTCOMMAND_H
#define IPLAYER_LOADPLAYLISTCOMMAND_H


#include "../Command/Command.h"

class LoadPlaylistCommand : public Command {
public:
    LoadPlaylistCommand(Receiver *receiver, string parameter): Command(receiver, parameter){}

    string execute();
};


#endif
