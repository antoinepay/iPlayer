//
// Created by Antoine Payan on 26/10/2017.
//
#include "Track.h"

Track::Track() {
    this->title = "";
    this->duration = 0;
    this->codecType = CODEC_TYPE::UNKNOWN;
}

Track::Track(string title, int duration, CODEC_TYPE codecType) {
    this->title = title;
    this->duration = duration;
    this->codecType = codecType;
}


string Track::getDescription() {
    string description = "/////////////////////////////////\n";
    description += "Track information\n";
    description += "Title : " + title + "\n";
    description += "Duration : " + to_string(duration) + "\n";
    description += "Codec : " + getCodecTitle() + "\n";
    description += "/////////////////////////////////\n";
    return description;
}

string Track::getTitle() {
    return title;
}


string Track::getCodecTitle() {
    switch (codecType) {
        case AAC:
            return "AAC";
        case MP3:
            return "MP3";
        case ALAC:
            return "ALAC";
        case WAV:
            return "WAV";
        case FLAC:
            return "FLAC";
        case VORBIS:
            return "VORBIS";
        default:
            return "Unknown";
    }
}

