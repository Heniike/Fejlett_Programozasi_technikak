//
// Created by asus on 11/12/2023.
//

#include "PlayList.h"
#include <algorithm>
#include <iostream>

using namespace std;

PlayList::PlayList(int capacity) : title(""), list(new Video *[capacity]), capacity(capacity), count(0) {}

PlayList::PlayList(const PlayList &copy) : title(copy.title), list(new Video *[copy.capacity]), capacity(copy.capacity),
                                           count(copy.count) {
    for (int i = 0; i < count; ++i) {
        list[i] = new Video(*(copy.list[i]));
    }
}

PlayList::PlayList(PlayList &&move) noexcept: title(move.title), list(move.list), capacity(move.capacity),
                                              count(move.count) {
    move.list = nullptr;
    move.count = 0;
}

PlayList::~PlayList() {
    for (int i = 0; i < count; ++i) {
        delete list[i];
    }
    delete[] list;
}

const string &PlayList::getTitle() const {
    return title;
}

void PlayList::setTitle(const string &title) {
    this->title = title;
}

int PlayList::videos() const {
    return count;
}

void PlayList::append(Video *video) {
    if (count < capacity) {
        list[count++] = video;
    } else {
        // Resize the list (you may choose a different resizing strategy)
        int newCapacity = capacity * 2;
        Video **newList = new Video *[newCapacity];

        // Copy existing elements to the new list
        for (int i = 0; i < count; ++i) {
            newList[i] = list[i];
        }

        // Add the new video to the new list
        newList[count++] = video;

        // Delete the old list and update the pointer
        delete[] list;
        list = newList;
        capacity = newCapacity;
    }
}

//void PlayList::sort(bool less(const Video &a, const Video &b)) {
//    std::sort(list, list + count, less);
//}

Video *PlayList::operator[](int index) {
    return list[index];
}

const Video *PlayList::operator[](int index) const {
    return list[index];
}

PlayList &PlayList::operator=(const PlayList &copy) {
    if (this != &copy) {
        // Release existing resources
        for (int i = 0; i < count; ++i) {
            delete list[i];
        }
        delete[] list;

        // Copy new values
        title = copy.title;
        capacity = copy.capacity;
        count = copy.count;
        list = new Video *[capacity];
        for (int i = 0; i < count; ++i) {
            list[i] = new Video(*(copy.list[i]));
        }
    }
    return *this;
}

PlayList &PlayList::operator=(PlayList &&move) noexcept {
    if (this != &move) {
        // Release existing resources
        for (int i = 0; i < count; ++i) {
            delete list[i];
        }
        delete[] list;

        // Move new values
        title = move.title;
        capacity = move.capacity;
        count = move.count;
        list = move.list;

        move.list = nullptr;
        move.count = 0;
    }
    return *this;
}

PlayList operator+(const PlayList &a, const PlayList &b) {
    PlayList result(a.capacity + b.capacity);
    result.setTitle(a.getTitle() + " + " + b.getTitle());

    for (int i = 0; i < a.videos(); ++i) {
        result.append(new Video(*(a[i])));
    }

    for (int i = 0; i < b.videos(); ++i) {
        result.append(new Video(*(b[i])));
    }

    return result;
}
//
//ostream &operator<<(ostream &os, const PlayList &list) {
//    os << "Playlist: " << list.getTitle() << "\n";
//    for (int i = 0; i < list.videos(); ++i) {
//        os << *(list[i]);
//    }
//    return os;
//}
ostream &operator<<(ostream &os, const PlayList &list) {
    os << "Title: " << list.title << endl;
    os << "Videos: " << endl;
    for (int i = 0; i < list.count; ++i) {
        os << *list.list[i] << endl;
    }
    return os;
}