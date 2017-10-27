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
        return new CreatePlaylistCommand(receiver, findParameter(line));
    } else if(commandWord == "add_track") {
        return new AddTrackCommand(receiver, findParameter(line));
    } else if(commandWord == "load_playlist") {
        return new LoadPlaylistCommand(receiver, findParameter(line));
    }
    return nullptr;
}

string CommandParser::findParameter(string line) {
    if(line.find(' ') != string::npos) {
        return line.substr(line.find(' ') + 1);
    } else {
        return "";
    }
}