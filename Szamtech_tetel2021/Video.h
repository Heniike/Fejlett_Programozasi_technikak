//
// Created by asus on 11/12/2023.
//

#ifndef SZAMTECH_TETEL2021_VIDEO_H
#define SZAMTECH_TETEL2021_VIDEO_H

#include <string>

using namespace std;

class Video {
private:
    string id;
    string title;
    double length;
    string uploader;
    long uploaded;

public:
    Video(const string &id, const string &title, double lenght, const string &uploader, long uploaded);
    const string &getId() const;
    const string &getTitle() const;
    double getLength() const;
    const string &getUploader() const;
    long getUploaded() const;
    friend ostream &operator<<(ostream &os, const Video &video);
};



#endif //SZAMTECH_TETEL2021_VIDEO_H
