//
// Created by Antoine Payan on 27/10/2017.
//

#include "NextCommand.h"

string NextCommand::execute() {
    receiver->setCommand(COMMAND_TYPE::NEXT, parameter);
    return receiver->getResult();
}