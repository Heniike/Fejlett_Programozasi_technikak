//
// Created by asus on 12/8/2023.
//

#include "Game.h"

Game::Game() : title(""), price(0.0){}

Game::Game(const string &title, double price) : title(title), price(price){}

Game::Game(const Game &other) : title(other.title), price(other.price){}

Game::Game(Game &&other) : title(move(other.title)), price(other.price){}

Game &Game::operator=(const Game &other) {
    if (this != &other) {
        title = other.title;
        price = other.price;
    }
    return *this;
}

Game &Game::operator=(Game &&other) {
    if(this != &other){
        title = move(other.title);
        price = other.price;
    }
    return *this;
}

std::string Game::getTitle() const {
    return title;
}

double Game::getPrice() const {
    return price;
}

bool Game::operator==(const Game &other) {
    if(title == other.title){
        return true;
    }
    return false;
}

std::ostream &operator<<(ostream &os, const Game &game) {
    os << "Title: " << game.title << ", price: " << game.price;
    return os;
}

std::istream &operator>>(istream &is, Game &game) {
    is >> game.title >> game.price;
    return is;
}

