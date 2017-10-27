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
        case REPEAT:
            return handleRepeat();
        case RANDOM:
            return handleRandom();
        case REMOVE_TRACK:
            return handleRemoveTrack();
        case REMOVE_DUPLICATES:
            return handleRemoveDuplicates();
        case NEXT:
            return handleNextCommand();

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
        nextTracks.clear();
        vector<Track*> *tracks = currentPlaylist->getTracks();
        for (vector<Track*>::iterator it = tracks->begin(); it!=tracks->end(); ++it) {
            nextTracks.push_back(*it);
        }
    }
}

REPEAT_MODE Player::parseRepeatMode(string parameter) {
    if(parameter == "all") {
        return ALL;
    } else if(parameter == "one") {
        return ONE;
    } else {
        return NO;
    }
}

string Player::getRepeatModeTitle(REPEAT_MODE mode) {
    switch (mode) {
        case ALL:
            return "all";
        case ONE:
            return "one";
        case NO:
            return "no";
    }
}

void Player::shuffleNextTracks() {
    vector<Track*> newNextTracks;
    while(!nextTracks.empty()) {
        int i = rand() % (int)nextTracks.size();
        newNextTracks.push_back(nextTracks[i]);
        nextTracks.erase(nextTracks.begin() + i);
    }
    nextTracks = newNextTracks;
}

void Player::restoreNextTracksOrder() {
    if(currentPlaylist == nullptr) {
        return;
    }
    vector<Track*> *playlistTracks = currentPlaylist->getTracks();
    vector<Track*> newNextTracks;
    for (vector<Track*>::iterator it = playlistTracks->begin(); it!=playlistTracks->end(); ++it) {
        for (vector<Track*>::iterator itNextTracks = nextTracks.begin(); itNextTracks!=nextTracks.end(); ++itNextTracks) {
            if((*it)->getTitle() == (*itNextTracks)->getTitle()) {
                newNextTracks.push_back(*itNextTracks);
            }
        }
    }
    nextTracks = newNextTracks;
}

bool Player::removeTrack(string &title) {
    if(currentPlaylist == nullptr) {
        return false;
    }
    bool deleted = false;
    vector<Track*> *playlistTracks = currentPlaylist->getTracks();
    for (vector<Track*>::iterator it = playlistTracks->begin(); it!=playlistTracks->end();) {
        if((*it)->getTitle() == title) {
            it = playlistTracks->erase(it);
            deleted = true;
        } else {
            ++it;
        }
    }
    for (vector<Track*>::iterator it = previousTracks.begin(); it<previousTracks.end();) {
        if((*it)->getTitle() == title) {
            it = previousTracks.erase(it);
            deleted = true;
        } else {
            ++it;
        }
    }
    for (vector<Track*>::iterator it = nextTracks.begin(); it<nextTracks.end();) {
        if((*it)->getTitle() == title) {
            it = nextTracks.erase(it);
            deleted = true;
        } else {
            ++it;
        }
    }
    return deleted;
}

string Player::getPreviousTracksList() {
    int i = 1;
    string list = "";
    for (vector<Track*>::iterator it = previousTracks.begin(); it!=previousTracks.end(); ++it) {
        list += "   - " + to_string(i++) + " : " + (*it)->getTitle() + "\n";
    }
    return i > 1 ? list : "None\n";
}

string Player::getNextTracksList() {
    int i = 1;
    string list = "";
    for (vector<Track*>::iterator it = nextTracks.begin(); it!=nextTracks.end(); ++it) {
        list += "   - " + to_string(i++) + " : " + (*it)->getTitle() + "\n";
    }
    return i > 1 ? list : "None\n";
}

bool Player::setRandom(bool enable) {
    random = enable;
    random ? shuffleNextTracks() : restoreNextTracksOrder();
    return random;
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
                currentPlaylist->addTrack(track);
                initNextTracks();
            } else {
                currentPlaylist->addTrack(track);
                nextTracks.push_back(track);
            }
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
        string description = "/////////////////////////////////\n";
        description += currentPlaylist->getDescription();
        description += "\nPrevious tracks :\n";
        description += getPreviousTracksList();
        description += "\nPlaying : \n";
        description += playing ? currentTrack->getDescription() : "None";
        description += "\n\nNext tracks :\n";
        description += getNextTracksList();
        description += "/////////////////////////////////\n";
        return description;
    }
    return "Error : No playlist loaded";
}

string Player::handleRepeat() {
    if(!parameterForCommand.empty()) {
        repeatMode = parseRepeatMode(parameterForCommand);
        return "Repeat mode set to "+getRepeatModeTitle(repeatMode);
    }
    return "Error : No repeat mode given!";
}

string Player::handleRandom() {
    if(!parameterForCommand.empty()) {
        if(parameterForCommand != "on" && parameterForCommand != "off") {
            return "Error : Random mode should be on or off";
        }
        setRandom(parameterForCommand == "on");
        string state = random ? "enable" : "disable";
        return "Random is " + state;
    }
    return "Error : Random mode not given, should be on or off";
}

string Player::handleRemoveTrack() {
    if(!parameterForCommand.empty()) {
        if(removeTrack(parameterForCommand)) {
            return "Track "+parameterForCommand+ " deleted";
        }
        return "Track "+parameterForCommand+ " not found";
    }
    return "Error : No track title given!";
}

string Player::handleRemoveDuplicates() {
    int deleted = currentPlaylist->removeDuplicates();
    initNextTracks();
    return to_string(deleted) + " tracks deleted";
}

string Player::handleNextCommand() {
    if(currentTrack != nullptr) {
        previousTracks.push_back(currentTrack);
    }
    bool loaded = loadNextTrack();
    playing = loaded;
    if(playing) {
        return "Player is now playing " + currentTrack->getTitle();
    } else {
        return "End of playlist";
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
