//
// Created by Antoine Payan on 26/10/2017.
//

#include "Playlist.h"

Playlist::Playlist() {
    this->title = "";
    this->modifiedAt = createdAt;
    this->totalDuration = 0;
}

Playlist::Playlist(string title) {
    this->title = title;
    this->modifiedAt = createdAt;
    this->totalDuration = 0;
}

void Playlist::addTrack(Track *track) {
    tracks.push_back(track);
}

void Playlist::removeTrack(string title) {
    for (vector<Track*>::iterator it = tracks.begin(); it != tracks.end(); ++it) {
        if((*it)->getTitle() == title) {
            tracks.erase(it);
        }
    }
}

Playlist::~Playlist() {
    for (vector<Track*>::iterator it = tracks.begin() ; it != tracks.end(); ++it) {
        delete (*it);
    }
    tracks.clear();
}