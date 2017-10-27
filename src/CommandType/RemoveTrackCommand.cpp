//
// Created by Antoine Payan on 27/10/2017.
//

#include "RemoveTrackCommand.h"

string RemoveTrackCommand::execute() {
    receiver->setCommand(COMMAND_TYPE::REMOVE_TRACK, parameter);
    return receiver->getResult();
}