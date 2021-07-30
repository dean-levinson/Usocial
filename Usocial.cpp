#include <string>
#include <list>
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
    /* todo: validate that the user is not in the list */
    /* todo: what if he is a friend of someone?
     maybe we should iterate over all of the users
     and delete the friend*/
    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->second == user) {
            users.erase(it);        
            break;
        }
    }
}

User* Usocial::getUserById(unsigned long id) {
    /* todo: validate that the user exists */
    auto it = users.find(id);
    return it->second;
}
