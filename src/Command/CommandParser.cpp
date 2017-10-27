//
// Created by Antoine Payan on 27/10/2017.
//

#include "CommandParser.h"

Command* CommandParser::parse(string line, Receiver *receiver) {
    string commandWord = line.substr(0, line.find(' '));
    string parameter = findParameter(line);
    if(commandWord == "play") {
        return new PlayCommand(receiver,parameter);
    } else if(commandWord == "pause") {
        return new PauseCommand(receiver,parameter);
    } else if(commandWord == "create_playlist") {
        return new CreatePlaylistCommand(receiver, parameter);
    } else if(commandWord == "add_track") {
        return new AddTrackCommand(receiver, parameter);
    } else if(commandWord == "load_playlist") {
        return new LoadPlaylistCommand(receiver, parameter);
    } else if(commandWord == "show_track") {
        return new ShowTrackCommand(receiver, parameter);
    } else if(commandWord == "show_playlist") {
        return new ShowPlaylistCommand(receiver, parameter);
    } else if(commandWord == "repeat") {
        return new RepeatCommand(receiver, parameter);
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