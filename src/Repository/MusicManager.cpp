//
// Created by Antoine Payan on 27/10/2017.
//

#include "MusicManager.h"

MusicManager MusicManager::m_instance=MusicManager();

MusicManager::MusicManager()
{
    cout<<"Initialization of Repository"<<endl;
    Track *t1 = new Track("pop_01.music",248,CODEC_TYPE::MP3);
    Track *t2 = new Track("electro_01.music",248,CODEC_TYPE::MP3);
    Track *t3 = new Track("jazz_01.music",480,CODEC_TYPE::WAV);
    Track *t4 = new Track("blues_01.music",300,CODEC_TYPE::WAV);
    Track *t5 = new Track("blues_02.music",360,CODEC_TYPE::WAV);
    library["pop_01.music"] = t1;
    library["electro_01.music"] = t2;
    library["jazz_01.music"] = t3;
    library["blues_01.music"] = t4;
    library["blues_02.music"] = t5;
}

MusicManager& MusicManager::Instance()
{
    return m_instance;
}

Track* MusicManager::getTrack(string title) {
    if(library.count(title) == 1) {
        return library[title];
    } else {
        return nullptr;
    }
}

MusicManager::~MusicManager()
{
    cout<<"Close Repository"<<endl;
}

