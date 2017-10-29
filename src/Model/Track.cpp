//
// Created by Antoine Payan on 26/10/2017.
//
#include "Track.h"

Track::Track() {
    title = "";
    duration = 0;
    codecType = CODEC_TYPE::UNKNOWN;
    samplingFrequency = 0;
}

Track::Track(string title, int duration, CODEC_TYPE codecType, int samplingFrequency) {
    this->title = title;
    this->duration = duration;
    this->codecType = codecType;
    this->samplingFrequency = samplingFrequency;
}


string Track::getDescription() {
    string description = "\n/////////////////////////////////\n";
    description += "Track information\n";
    description += "Title : " + title + "\n";
    description += "Duration : " + to_string(duration) + "\n";
    description += "Codec : " + getCodecTitle() + "\n";
    description += "Sampling frequency : " + to_string(samplingFrequency) + " Hz\n";
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

