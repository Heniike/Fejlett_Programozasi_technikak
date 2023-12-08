//
// Created by asus on 11/12/2023.
//

#include "Video.h"
#include <iostream>

using namespace std;

Video::Video(const string &id, const string &title, double lenght, const string &uploader, long uploaded) :
    id(id), title(title), length(length), uploader(uploader), uploaded(uploaded){}

const string &Video::getId() const {
    return id;
}
const string &Video::getTitle() const {
    return title;
}

double Video::getLength() const {
    return length;
}

const string &Video::getUploader() const {
    return uploader;
}

long Video::getUploaded() const {
    return uploaded;
}

ostream &operator<<(ostream &os, const Video &video) {
    os << "ID: " << video.getId() << "\nTitle: " << video.getTitle() << "\nLength: " << video.getLength()
       << "\nUploader: " << video.getUploader() << "\nUploaded: " << video.getUploaded() << "\n";
    return os;
}


