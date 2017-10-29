//
// Created by Antoine Payan on 27/10/2017.
//

#include "AddTrackCommand.h"

string AddTrackCommand::execute() {
    receiver->setCommand(COMMAND_TYPE::ADD_TRACK, parameter);
    return receiver->getResult();
}