//
// Created by asus on 12/7/2023.
//

#ifndef LAB6_SONG_H
#define LAB6_SONG_H

#include <iostream>
using namespace std;

class Song {
public:
// Constructors
    Song();
    Song(const string &title, const string &artist, int duration);
    Song(const Song &other);
    Song(Song &&other);
// Assignment operators
    Song& operator=(const Song &other);
    Song& operator=(Song &&other);
// Getter methods
    string getTitle() const;
    string getArtist() const;
    int getDuration() const;
    int getMinutes() const;
    int getSeconds() const;
// Equality operator overloading
    bool operator==(const Song &other);
// Inserter operator
    friend ostream& operator<<(ostream &os, const Song &song);
// Extractor operator
    friend istream& operator>>(istream &is, Song &song);
private:
// Helper methods
    string padNumber(int number) const;
    string title;
    string artist;
    int duration;
};


#endif //LAB6_SONG_H
