//
// Created by Antoine Payan on 27/10/2017.
//

#include "MusicManager.h"

MusicManager MusicManager::m_instance=MusicManager();

MusicManager::MusicManager()
{
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

    Track *t6 = new Track("1",248,CODEC_TYPE::MP3);
    Track *t7 = new Track("2",248,CODEC_TYPE::MP3);
    Track *t8 = new Track("3",248,CODEC_TYPE::MP3);
    library["1"] = t6;
    library["2"] = t7;
    library["3"] = t8;
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

}

