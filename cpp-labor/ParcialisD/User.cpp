//
// Created by asus on 12/8/2023.
//

#include <algorithm>
#include "User.h"

User::User() : username(""), wishlist({}){}

User::User(const string &username) : username(username), wishlist({}){}

User::User(const User &other) : username(other.username), wishlist(other.wishlist){}

User::User(User &&other) : username(move(other.username)), wishlist(move(other.wishlist)){}

User &User::operator=(const User &other) {
    if(this != &other){
        username = other.username;
        wishlist = other.wishlist;
    }
    return *this;
}

User &User::operator=(User &&other) {
    if(this != &other){
        username = move(other.username);
        wishlist = move(other.wishlist);
    }
    return *this;
}

std::string User::getUsername() const {
    return username;
}

void User::addToWishlist(const Game &game) {
//    for(const auto &g : wishlist){
//        if(g == game){
//            throw invalid_argument("Game already in wishlist.");
//        }
//    }
    for (int i = 0; i < wishlist.size(); i++) {
        if (wishlist[i] == game) {
            throw invalid_argument("Game already in wishlist.");
        }
    }
    wishlist.push_back(game);
}

void User::removeFromWishlist(const string &gameTitle) {
    wishlist.erase(remove_if(wishlist.begin(), wishlist.end(), [&gameTitle](const Game &g) {
        return g.getTitle() == gameTitle;
    }), wishlist.end());

}

void User::sortWishlistBy(SortOption option) {
    if(option == BY_TITLE){
        sort(wishlist.begin(), wishlist.end(), [](const Game &g1, const Game &g2){
            return g1.getTitle() < g2.getTitle();
        });
    }else if(option == BY_PRICE){
        sort(wishlist.begin(), wishlist.end(), [](const Game &g1, const Game &g2){
            return g1.getPrice() < g2.getPrice();
        });
    }
}

std::ostream &operator<<(ostream &os, const User &user) {
    os << "Username: " << user.username << "\nWishlist:\n";
    for(const auto &game : user.wishlist){
        os << game << endl;
    }
    return os;
}

std::istream &operator>>(istream &is, User &user) {
    is >> user.username;
    size_t numGames;
    is >> numGames;
    for (size_t i = 0; i < numGames; ++i) {
        Game game;
        is >> game;
        user.addToWishlist(game);
    }
    return is;
}





