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