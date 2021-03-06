//
// Created by Antoine Payan on 26/10/2017.
//

#ifndef IPLAYER_RECEIVER_H
#define IPLAYER_RECEIVER_H

#include <string>

using namespace std;

enum COMMAND_TYPE
{
    PLAY,
    PAUSE,
    CREATE_PLAYLIST,
    ADD_TRACK,
    LOAD_PLAYLIST,
    SHOW_TRACK,
    SHOW_PLAYLIST,
    REPEAT,
    RANDOM,
    REMOVE_TRACK,
    REMOVE_DUPLICATES,
    NEXT,
    PREVIOUS,
    HELP,
    NONE
    // Add other commands
};

class Receiver {

public:
    virtual void setCommand(COMMAND_TYPE commandType, string parameter) = 0;
    virtual string getResult() = 0;

};

#endif
