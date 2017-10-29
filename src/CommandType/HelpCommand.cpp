//
// Created by Antoine Payan on 28/10/2017.
//

#include "HelpCommand.h"

string HelpCommand::execute() {
    receiver->setCommand(COMMAND_TYPE::HELP, parameter);
    return receiver->getResult();
}