//
// Created by Antoine Payan on 27/10/2017.
//

#include "PreviousCommand.h"

string PreviousCommand::execute() {
    receiver->setCommand(COMMAND_TYPE::PREVIOUS, parameter);
    return receiver->getResult();
}