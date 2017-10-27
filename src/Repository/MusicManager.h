//
// Created by Antoine Payan on 27/10/2017.
//

#ifndef IPLAYER_MUSICMANAGER_H
#define IPLAYER_MUSICMANAGER_H

#include <iostream>
#include <map>
#include "../Model/Track.h"

using namespace std;

class MusicManager {
public:
    static MusicManager& Instance();
    Track* getTrack(string title);
private:
    MusicManager& operator= (const MusicManager&){}
    MusicManager (const MusicManager&){}

    static MusicManager m_instance;
    map<string, Track*> library;
    MusicManager();
    ~MusicManager();
};


#endif
