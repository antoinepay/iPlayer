//
// Created by Antoine Payan on 27/10/2017.
//

#include "ShowTrackCommand.h"

string ShowTrackCommand::execute() {
    receiver->setCommand(COMMAND_TYPE::SHOW_TRACK, parameter);
    return receiver->getResult();
}