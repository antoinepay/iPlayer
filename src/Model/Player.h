//
// Created by Antoine Payan on 26/10/2017.
//

#ifndef IPLAYER_PLAYER_H
#define IPLAYER_PLAYER_H

#include <map>
#include "../Command/Receiver.h"
#include "Playlist.h"

enum REPEAT_MODE {
    ONE,
    ALL,
    NO
};

class Player : public Receiver {

public:
    Player();

    virtual ~Player();
private:
    bool playing;
    Track *currentTrack;
    map<string, Playlist*> playlists;
    REPEAT_MODE repeatMode;
    bool random;
    vector<Track*> previousTracks;
    vector<Track*> nextTracks;
};


#endif
