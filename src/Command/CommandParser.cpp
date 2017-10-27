//
// Created by Antoine Payan on 27/10/2017.
//

#include "CommandParser.h"

Command* CommandParser::parse(string line, Receiver *receiver) {
    string commandWord = line.substr(0, line.find(' '));
    string parameter;
    if(commandWord == "play") {
        return new PlayCommand(receiver,"");
    } else if(commandWord == "pause") {
        return new PauseCommand(receiver,"");
    } else if(commandWord == "create_playlist") {
        if(line.find(' ') != string::npos) {
            parameter = line.substr(line.find(' ') + 1);
        } else {
            parameter = "";
        }
        return new CreatePlaylistCommand(receiver, parameter);
    }
    return nullptr;
}