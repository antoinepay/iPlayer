//
// Created by Antoine Payan on 26/10/2017.
//

#ifndef IPLAYER_TRACK_H
#define IPLAYER_TRACK_H

#include <iostream>
#include <string>

using namespace std;

enum CODEC_TYPE {
    MP3,
    WAV,
    FLAC,
    ALAC,
    AAC,
    VORBIS,
    UNKNOWN
};

class Track {

public:
    Track();
    Track(string title, int duration, CODEC_TYPE codecType, int samplingFrequency);

    string getDescription();
    string getTitle();

    virtual ~Track() {}

private:
    string title;
    int duration;
    CODEC_TYPE codecType;
    int samplingFrequency;

    string getCodecTitle();
};


#endif
