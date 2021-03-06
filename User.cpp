#include <iostream>
#include <string>
#include <list>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include "User.h"

using namespace std;

User::User() {};

User::~User() {
    // Delete own posts
    for (auto posts_it = posts.begin(); posts_it != posts.end(); ++posts_it) {
        delete *posts_it;
    };

    // Delete received messages
    for (auto msgs_it = receivedMsgs.begin(); msgs_it != receivedMsgs.end(); ++msgs_it) {
        delete *msgs_it;
    };
};

unsigned long User::getId() {
    return id;
};

string User::getName() {
    return name;
};

bool User::isFriend(User* other) {
    return (count(friends.begin(), friends.end(), other->getId()) > 0);
};

void User::addFriend(User* other) {
    if (isFriend(other)) {
        throw logic_error( other->name + " is already in the friends list" );
    }

    if (other->id == id) {
        throw logic_error( "A user cannot be a friend of himself" );
    }

    friends.push_back(other->id);
};

void User::removeFriend(User* other) {
    if (!isFriend(other)) {
        throw logic_error( other->name + " is not in the friends list" );
    }

    friends.remove(id);
};

void User::post(string text) {
    /* auto post = make_shared<Post>(text); */ 
    Post* post = new Post(text);

    posts.push_back(post);
};

void User::post(string text, Media* media) {
    /* auto post = make_shared<Post>(text, media); */
    Post* post = new Post(text, media);

    posts.push_back(post);
};

list<Post*> User::getPosts() {
    return posts;
};

void User::viewFriendsPosts() {
    cout << name << " friend's posts:" << endl;
    User* friend_user;
    list<Post*> friend_posts;
    for (auto it = friends.begin(); it != friends.end(); ++it) {
        friend_user = us->getUserById(*it);
        friend_posts = friend_user->getPosts();
        for (auto second_it = friend_posts.begin(); second_it != friend_posts.end(); ++second_it) {
            cout << friend_user->name << " post: " << (*(*second_it)) << endl;
        };
    };
};

void User::viewFriends() {
    for_each(friends.begin(), friends.end(), [this](unsigned long id) {
            if (this->us->isIdExists(id)) {
                cout << this->us->getUserById(id)->getName() << endl; 
            };
    });
};

void User::receiveMessage(Message* message) {
    receivedMsgs.push_back(message);
};

void User::_sendMessage(User* target, Message* message) {
    message->add_author(name);
    target->receiveMessage(message);
};

void User::sendMessage(User* target, Message* message) {
    if (!isFriend(target)) {
        throw logic_error("Regular user cannot send a message to a none friend user");
    }
    _sendMessage(target, message);
};

void User::viewReceivedMessages() {
    cout << name << "'s messages:" << endl;
    for (auto it = receivedMsgs.begin(); it != receivedMsgs.end(); ++it) {
        cout << (*it)->getText() << endl;
    }
};

BusinessUser::BusinessUser() {};

void BusinessUser::sendMessage(User* target, Message* message) {
    // Sends without validations
    _sendMessage(target, message);
}