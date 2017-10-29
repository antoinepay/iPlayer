//
// Created by Antoine Payan on 27/10/2017.
//

#include "CreatePlaylistCommand.h"

string CreatePlaylistCommand::execute() {
    receiver->setCommand(COMMAND_TYPE::CREATE_PLAYLIST, parameter);
    return receiver->getResult();
}