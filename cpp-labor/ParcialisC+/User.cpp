//
// Created by asus on 12/8/2023.
//

#include <algorithm>
#include "User.h"

int User::nextId = 1;

User::User() : id(nextId++){}

User::User(const string &username) : id(nextId++), username(username){}

User::User(const User &other) : id(other.id), username(other.username),
    playlist(other.playlist){}

User::User(User &&other) noexcept : id(other.id), username(move(other.username)),
    playlist(move(other.playlist)){}

User &User::operator=(const User &other) {
    if(this != &other){
        id = other.id;
        username = other.username;
        playlist = other.playlist;
    }
    return *this;
}

User &User::operator=(User &&other) noexcept{
    if(this != &other){
        id = other.id;
        username = move(other.username);
        playlist = move(other.playlist);
    }
    return *this;
}

int User::getId() const {
    return id;
}

string User::getUsername() const {
    return username;
}

const vector<Song> &User::getPlaylist() const {
    return playlist;
}

void User::addToPlaylist(const Song &song) {
    for(auto existingsong : playlist){
        if(existingsong == song){
            throw invalid_argument("Song already exists in playlist");
        }
    }
    playlist.push_back(song);
    //    for (int i = 0; i < playlist.size(); i++) {
//        if (playlist[i] == song) {
//            throw invalid_argument("Song already exists in playlist");
//        }
//    }
}

int User::removeArtistFromPlaylist(const string &artist) {
//    int counter = 0;
//    playlist.erase(remove_if(playlist.begin(), playlist.end(),
//                             [artist](const Song &song) {
//                                 return song.getArtist() == artist;
//                             }), playlist.end());
//    return counter;
    auto originalSize = playlist.size();
    playlist.erase(std::remove_if(playlist.begin(), playlist.end(),
                                  [artist](const Song &song) { return song.getArtist() == artist; }),
                   playlist.end());
    return originalSize - playlist.size();
}

int User::removeShortSongsFromPlaylist(int minDuration) {
//    int counter = 0;
//    playlist.erase(remove_if(playlist.begin(), playlist.end(),
//                             [minDuration](const Song &song) {
//                                 return song.getMinutes() < minDuration;
//                             }), playlist.end());
//    return counter;
    auto originalSize = playlist.size();
    playlist.erase(std::remove_if(playlist.begin(), playlist.end(),
                                  [minDuration](const Song &song) { return song.getDuration() < minDuration; }),
                   playlist.end());
    return originalSize - playlist.size();
}

void User::sortPlaylistBy(SortOption option) {
    switch (option) {
        case BY_TITLE:
            sort(playlist.begin(), playlist.end(),
                 [](const Song &a, const Song &b) {
                     return a.getTitle() < b.getTitle();
                 }
            );
            break;
        case BY_ARTIST:
            sort(playlist.begin(), playlist.end(),
                 [](const Song &a, const Song &b) {
                     return a.getArtist() < b.getArtist();
                 }
            );
            break;
        case BY_DURATION:
            sort(playlist.begin(), playlist.end(),
                 [](const Song &a, const Song &b) {
                     return a.getMinutes() < b.getMinutes();
                 }
            );
            break;
        default:
            break;
    }
}

ostream &operator<<(ostream &os, const User &user) {
    os << "User ID: " << user.getId() << ", Username: " << user.getUsername() << ", Playlist: " << endl;
    for(const auto &song : user.getPlaylist()){
        os << "\t- " << song << endl;
    }
    return os;
}

istream &operator>>(istream &is, User &user) {
    is >> user.username;
    int numSongs;
    is >> numSongs;
    for (int i = 0; i < numSongs; ++i) {
        Song song;
        is >> song;
        user.addToPlaylist(song);
    }
    return is;

}



