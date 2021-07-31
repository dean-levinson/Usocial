#include <string>
#include <list>
#include <stdexcept>
#include "Usocial.h"

Usocial::~Usocial() {
    // Delete all the users.
    for (auto it = users.begin(); it != users.end(); ++it) {
        delete it->second;
    };
}

unsigned long Usocial::GetAvailableID() {
    unsigned long found_id = 0;
    while (1) {
        if (!users.count(found_id)) {
            /* It means that we've found an unused id */
            return found_id;
        };
        found_id += 1;
    };
}

User* Usocial::registerUser(string name, bool is_business_account) {
    User* new_user;
    unsigned long id = GetAvailableID();

    if (is_business_account) {
        new_user = new BusinessUser();
    } else {
        new_user = new User();
    }

    /* Configure user */
    new_user->us = this;
    new_user->name = name;
    new_user->id = id;

    users.insert(pair<unsigned long, User*>(id, new_user));

    return new_user;
}

void Usocial::removeUser(User* user) {
    bool is_found = false;

    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->second == user) {
            is_found = true;
            // Delete the user from all the friends lists he is in.
            // We would iterate over the user we want to delete but it's OK because he won't be in his own friends list.
            for (auto second_it = users.begin(); second_it != users.end(); ++second_it) {
                if (second_it->second->isFriend(it->second)) {
                    second_it->second->removeFriend(it->second);
                };
            }
            users.erase(it); // Delete the user from the social media.
            break; // Exit for loop.
        }
    }

    if (!is_found) {
        throw logic_error( "The user is not part of the social media");
    }
}

User* Usocial::getUserById(unsigned long id) {
    if (!isIdExists(id)) {
        throw logic_error( "The ID does not exist in the social media");
    };

    auto it = users.find(id);
    return it->second;
}

bool Usocial::isIdExists(unsigned long id) {
    return (users.count(id) > 0);
}
