//
// Created by Antoine Payan on 27/10/2017.
//

#include "RepeatCommand.h"

string RepeatCommand::execute() {
    receiver->setCommand(COMMAND_TYPE::REPEAT, parameter);
    return receiver->getResult();
}