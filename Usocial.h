#ifndef USOCIAL_H_
#define USOCIAL_H_

#include <string>
#include <list>
#include <map>
#include "User.h"

using namespace std;

class User;
class BusinessUser;

class Usocial
{
private:
    map<unsigned long, User*> users;
    unsigned long GetAvailableID();
public:
    ~Usocial();
    /**
     * Register a new user to the social media.
     * 
     * @param name - The new user name.
     * @param is_business_user - bool that indicates weather the user is a business user or a regular one.
     * @return A pointer to the user object.
     */
    User* registerUser(string name, bool is_business_user  = false);

    /**
     * Removes a user from the social media.
     * 
     * @param user - A pointer to the user who needs to remove.
     */
    void removeUser(User* user);

    /**
     * Gets a user By his id.
     * 
     * @param id - the id of the user
     * @return The user object.
     */
    User* getUserById(unsigned long id);
};

#endif /* USOCIAL_H_ */