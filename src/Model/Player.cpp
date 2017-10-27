//
// Created by Antoine Payan on 26/10/2017.
//

#include "Player.h"

Player::Player() {
    this->playing = false;
    this->random = false;
    this->repeatMode = REPEAT_MODE::NO;
    this->currentTrack = nullptr;
    this->currentCommand = COMMAND_TYPE::NONE;
    this->parameterForCommand = "";
    this->currentPlaylist = nullptr;
}

void Player::setCommand(COMMAND_TYPE commandType, string parameter) {
    currentCommand = commandType;
    parameterForCommand = parameter;
}

string Player::getResult() {
    switch (currentCommand) {
        case PLAY:
            return handlePlay();
        case PAUSE:
            playing = false;
            return "Player is paused";
        case CREATE_PLAYLIST:
            return handleCreatePlaylist();
        case ADD_TRACK:
            return handleAddTrack();
        case LOAD_PLAYLIST:
            return handleLoadPlaylist();
        case SHOW_TRACK:
            return handleShowTrack();
        case SHOW_PLAYLIST:
            return handleShowPlaylist();

    }
}

bool Player::isTrackLoaded() {
    return currentTrack != nullptr;
}

bool Player::loadNextTrack() {
    if(!nextTracks.empty()) {
        currentTrack = nextTracks.front();
        nextTracks.erase(nextTracks.begin());
        return true;
    }
    return false;
}

void Player::initNextTracks() {
    if(currentPlaylist != nullptr) {
        vector<Track*> *tracks = currentPlaylist->getTracks();
        for (vector<Track*>::iterator it = tracks->begin(); it!=tracks->end(); ++it) {
            nextTracks.push_back(*it);
        }
    }
}


// Command handlers

string Player::handlePlay() {
    if(isTrackLoaded()) {
        playing = true;
    } else if(loadNextTrack()) {
        playing = true;
    } else {
        return "Impossible to play, no musics loaded";
    }
    return "Player is now playing " + currentTrack->getTitle();
}

string Player::handleCreatePlaylist() {
    if(!parameterForCommand.empty()) {
        Playlist *playlist = new Playlist(parameterForCommand);
        playlists[parameterForCommand] = playlist;
        return "Playlist " + parameterForCommand + " created";
    } else {
        return "Error : No playlist title given!";
    }
}

string Player::handleAddTrack() {
    if(!parameterForCommand.empty()) {
        MusicManager &musicManager = MusicManager::Instance();
        Track *track = musicManager.getTrack(parameterForCommand);
        if(track != nullptr) {
            if(currentPlaylist == nullptr) {
                string playlistTitle = "New playlist";
                currentPlaylist = new Playlist(playlistTitle);
                playlists[playlistTitle] = currentPlaylist;
            }
            currentPlaylist->addTrack(track);
            return "Track "+track->getTitle()+ " added to "+currentPlaylist->getTitle();
        } else {
            return "Error : Music not found";
        }
    } else {
        return "Error : No music title given!";
    }
}

string Player::handleLoadPlaylist() {
    if(playlists.count(parameterForCommand) == 1) {
        currentPlaylist = playlists[parameterForCommand];
        initNextTracks();
        return "Playlist "+currentPlaylist->getTitle()+" loaded";
    }
    return "Error : Playlist not found";
}

string Player::handleShowTrack() {
    if (currentTrack != nullptr) {
        return currentTrack->getDescription();
    }
    return "Error : No track loaded";
}

string Player::handleShowPlaylist() {
    if(currentPlaylist != nullptr) {
        return currentPlaylist->getDescription();
    }
    return "Error : No playlist loaded";
}

Player::~Player() {
    delete currentTrack;
    for (vector<Track *>::iterator it = previousTracks.begin(); it != previousTracks.end(); ++it) {
        delete (*it);
    }
    previousTracks.clear();
    for (vector<Track *>::iterator it = nextTracks.begin(); it != nextTracks.end(); ++it) {
        delete (*it);
    }
    nextTracks.clear();
    for (map<string, Playlist *>::iterator it = playlists.begin(); it != playlists.end(); ++it) {
        delete it->second;
    }
    playlists.clear();
}