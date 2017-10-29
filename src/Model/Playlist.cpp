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

int Playlist::removeDuplicates() {
    int deleted = 0;
    for (vector<Track*>::iterator it = tracks.begin(); it != tracks.end();++it) {
        for (vector<Track*>::iterator itDel = it+1; itDel != tracks.end();) {
            if((*it)->getTitle() == (*itDel)->getTitle()) {
                itDel = tracks.erase(itDel);
                deleted++;
            } else {
                itDel++;
            }
        }
    }
    return deleted;
}

string Playlist::getTitle() {
    return title;
}

vector<Track*>* Playlist::getTracks() {
    return &tracks;
}

string Playlist::getDescription() {
    string description = "\n/////////////////////////////////\n";
    description += "Playlist information\n";
    description += "Title : "+title +"\n";
    description += "Tracks : \n";
    if(tracks.empty()) {
        description += "No tracks in the playlist\n";
    } else {
        for (int i = 0; i < tracks.size(); i++) {
            description += "   - " +to_string(i+1) + " : " + tracks[i]->getTitle() + "\n";
        }
    }
    description += "/////////////////////////////////\n";
    return description;
}

Playlist::~Playlist() {
    for (vector<Track *>::iterator it = tracks.begin(); it != tracks.end(); ++it) {
        delete (*it);
    }
    tracks.clear();
}