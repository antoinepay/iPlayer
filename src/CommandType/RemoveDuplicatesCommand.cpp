//
// Created by Antoine Payan on 27/10/2017.
//

#include "RemoveDuplicatesCommand.h"

string RemoveDuplicatesCommand::execute() {
    receiver->setCommand(COMMAND_TYPE::REMOVE_DUPLICATES,parameter);
    return receiver->getResult();
}