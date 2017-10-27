//
// Created by Antoine Payan on 27/10/2017.
//

#include "RandomCommand.h"

string RandomCommand::execute() {
    receiver->setCommand(COMMAND_TYPE::RANDOM, parameter);
    return receiver->getResult();
}