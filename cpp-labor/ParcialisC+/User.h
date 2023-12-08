//
// Created by asus on 12/8/2023.
//

#ifndef PARCIALISC_USER_H
#define PARCIALISC_USER_H
using namespace std;
#include <iostream>
#include "Song.h"
#include <vector>

// Enum for sorting options
enum SortOption {
    BY_TITLE,
    BY_ARTIST,
    BY_DURATION
};
class User {
public:
    /// Constructors
    User();
    User(const string &username);
    User(const User &other);
    User(User &&other) noexcept;
    /// Assignment operators
    User& operator=(const User &other);
    User& operator=(User &&other) noexcept;
    /// Getter methods
    int getId() const;
    string getUsername() const;
    const vector<Song> &getPlaylist() const;
    /// Playlist management
    void addToPlaylist(const Song &song);
    int removeArtistFromPlaylist(const string &artist);
    int removeShortSongsFromPlaylist(int minDuration);
    /// Sort playlist by name or price
    void sortPlaylistBy(SortOption option);
    friend ostream& operator<<(ostream &os, const User &user);
    friend istream& operator>>(istream &is, User &user);
private:
    int id;
    string username;
    vector<Song> playlist;
    /// First user's ID must be 1
    static int nextId;
};


#endif //PARCIALISC_USER_H
