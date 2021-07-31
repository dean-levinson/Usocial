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
     * Removes a user from the social media. Raises logic_error if the user is not exists.
     * If the user is in the friends list of other users, removes him from there.
     * 
     * @param user - A pointer to the user who needs to be removed from the us.
     */
    void removeUser(User* user);

    /**
     * Gets a user By his id. Raises logic_error if there is not user with such id.
     * 
     * @param id - the id of the user
     * @return The user object.
     */
    User* getUserById(unsigned long id);

    /**
     * Returns weather there is user with this ID in the social media.
     */
    bool isIdExists(unsigned long id);
};

#endif /* USOCIAL_H_ */