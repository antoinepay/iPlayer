//
// Created by Antoine Payan on 27/10/2017.
//

#include "PauseCommand.h"

string PauseCommand::execute() {
    receiver->setCommand(COMMAND_TYPE::PAUSE, parameter);
    return receiver->getResult();
}