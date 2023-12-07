//
// Created by asus on 12/7/2023.
//

#include "Song.h"

Song::Song() : duration(0){}

Song::Song(const string &title, const string &artist, int duration) {

}

Song::Song(const Song &other) : title(other.title), artist(other.title), duration(other.duration){}

Song::Song(Song &&other)  :
    title(move(other.title)), artist(move(other.artist)),
    duration(other.duration){}

//Song &Song::operator=(const Song &other) {
//    return <#initializer#>;
//}

