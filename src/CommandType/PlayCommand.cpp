//
// Created by Antoine Payan on 26/10/2017.
//

#include "PlayCommand.h"

string PlayCommand::execute() {
    receiver->setCommand(COMMAND_TYPE::PLAY, parameter);
    return receiver->getResult();
}