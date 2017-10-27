//
// Created by Antoine Payan on 26/10/2017.
//

#ifndef IPLAYER_PLAYLIST_H
#define IPLAYER_PLAYLIST_H

#include <vector>
#include <string>
#include <ctime>
#include "Track.h"

using namespace std;

class Playlist {
public:
    Playlist();
    Playlist(string title);

    void addTrack(Track *track);
    void removeTrack(string title);
    int removeDuplicates();

    string getTitle();
    vector<Track*>* getTracks();

    virtual ~Playlist();

private:
    string title;
    vector<Track*> tracks;
    const time_t createdAt = time(nullptr);
    time_t modifiedAt;
    int totalDuration;
};


#endif
