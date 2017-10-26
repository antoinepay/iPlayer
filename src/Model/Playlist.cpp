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

Playlist::~Playlist() {
    for (vector<Track*>::iterator it = tracks.begin() ; it != tracks.end(); ++it) {
        delete (*it);
    }
    tracks.clear();
}