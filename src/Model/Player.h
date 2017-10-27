//
// Created by Antoine Payan on 26/10/2017.
//

#ifndef IPLAYER_PLAYER_H
#define IPLAYER_PLAYER_H

#include <map>
#include "../Command/Receiver.h"
#include "Playlist.h"
#include "../Repository/MusicManager.h"

enum REPEAT_MODE {
    ONE,
    ALL,
    NO
};

class Player : public Receiver {

public:
    Player();
    void setCommand(COMMAND_TYPE commandType, string parameter);
    string getResult();


    virtual ~Player();
private:
    COMMAND_TYPE currentCommand;
    string parameterForCommand;
    bool playing;
    Track *currentTrack;
    map<string, Playlist*> playlists;
    Playlist *currentPlaylist;
    REPEAT_MODE repeatMode;
    bool random;
    vector<Track*> previousTracks;
    vector<Track*> nextTracks;

    bool isTrackLoaded();
    bool loadNextTrack();

    // Command handlers
    string handlePlay();
    string handleCreatePlaylist();
    string handleAddTrack();
};


#endif
