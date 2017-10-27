//
// Created by Antoine Payan on 27/10/2017.
//

#include "LoadPlaylistCommand.h"

string LoadPlaylistCommand::execute() {
    receiver->setCommand(COMMAND_TYPE::LOAD_PLAYLIST, parameter);
    return receiver->getResult();
}