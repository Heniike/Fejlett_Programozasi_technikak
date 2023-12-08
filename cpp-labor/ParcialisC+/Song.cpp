//
// Created by asus on 12/7/2023.
//

#include "Song.h"

Song::Song() : duration(0){}

Song::Song(const string &title, const string &artist, int duration) {

}

Song::Song(const Song &other) : title(other.title), artist(other.title), duration(other.duration){}

Song::Song(Song &&other)  noexcept:
    title(move(other.title)), artist(move(other.artist)),
    duration(other.duration){}

Song &Song::operator=(const Song &other) {
    if (this != &other) {
        title = other.title;
        artist = other.artist;
        duration = other.duration;
    }
    return *this;
}

Song &Song::operator=(Song &&other)noexcept {
    if (this != &other) {
        title = move(other.title);
        artist = move(other.artist);
        duration = other.duration;
    }
    return *this;
}

string Song::getTitle() const {
    return title;
}

string Song::getArtist() const {
    return artist;
}

int Song::getDuration() const {
    return duration;
}

int Song::getMinutes() const {
    return duration / 60;
}

int Song::getSeconds() const {
    return duration % 60;
}

bool Song::operator==(const Song &other) {
    return (title == other.title) && (artist == other.artist);
}


string Song::padNumber(int number) const {
    return (number < 10) ? "0" + to_string(number) : to_string(number);
}

ostream &operator<<(ostream &os, const Song &song) {
    os << song.title << " by " << song.artist << " (" <<
        song.getMinutes() << ":" << song.getSeconds() << ")";
    return os;
}

istream &operator>>(istream &is, Song &song) {
    is >> song.title >> song.artist >> song.duration;
    return is;
}


