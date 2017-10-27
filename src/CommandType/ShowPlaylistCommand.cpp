//
// Created by Antoine Payan on 27/10/2017.
//

#include "ShowPlaylistCommand.h"

string ShowPlaylistCommand::execute() {
    receiver->setCommand(COMMAND_TYPE::SHOW_PLAYLIST, parameter);
    return receiver->getResult();
}