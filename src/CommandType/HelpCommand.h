//
// Created by Antoine Payan on 28/10/2017.
//

#ifndef IPLAYER_HELPCOMMAND_H
#define IPLAYER_HELPCOMMAND_H

#include "../Command/Command.h"

class HelpCommand : public Command {
public:
    HelpCommand(Receiver *receiver, string parameter): Command(receiver, parameter){}

    string execute();
};


#endif
