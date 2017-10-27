//
// Created by Antoine Payan on 27/10/2017.
//

#ifndef IPLAYER_COMMANDPARSER_H
#define IPLAYER_COMMANDPARSER_H

#include <string>
#include "Command.h"
#include "../CommandType/PlayCommand.h"
#include "../CommandType/PauseCommand.h"
#include "../CommandType/CreatePlaylistCommand.h"
#include "../CommandType/AddTrackCommand.h"
#include "../CommandType/LoadPlaylistCommand.h"
#include "../CommandType/ShowTrackCommand.h"
#include "../CommandType/ShowPlaylistCommand.h"
#include "../CommandType/RepeatCommand.h"

using namespace std;

class CommandParser {
public:
    static Command* parse(string line, Receiver *receiver);
private:
    CommandParser() {}
    static string findParameter(string line);
};


#endif
