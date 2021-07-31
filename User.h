#ifndef USER_H_
#define USER_H_

#include <string>
#include <list>
#include <exception>
#include "Post.h"
#include "Message.h"
#include "Media.h"
#include "Usocial.h"


using namespace std;

class Usocial;

class User
{
    friend class Usocial;

protected:
    Usocial* us; 
    unsigned long id; 
    string name; 
    list<unsigned long> friends; 
    list<Post*> posts; 
    list<Message*> receivedMsgs; 
    User();
    virtual ~User();

public:
    /**
     * Returns the Id of the user
     * 
     * @return unsigned long 
     */
    unsigned long getId();

    /**
     * Returns the Name of the user.
     * 
     * @return string 
     */
    string getName();

    /**
     * Returns weather the other user is in the friends list. 
     * 
     * @param other - The other user.
     */
    bool isFriend(User* other);

    /**
     * Add a friend to the user. Raises logic_error if this user is already in the friends list,
     *  or if other is himself (User connot be a friend of himself).
     * 
     * @param other The friend you want to add to the user.
     */
    void addFriend(User* other);

    /**
     * Removes a friend from the user. Raises logic_error if this user is not in the friends list.
     * 
     * @param other the friend who should be removed.
     */
    void removeFriend(User* other);

    /**
     * Posts a text in the user's feed.
     * 
     * @param text - The text in the post.
     */
    void post(string text);

    /**
     * Posts a text + media in the user's feed.
     * 
     * @param text - The text in the post.
     * @param media - The media in the post.
     */
    void post(string text, Media* media);

    /**
     * Returns the posts of the user.
     * 
     * @return A list the contains the post's ptr of the users.
     */
    list<Post*> getPosts();

    /**
     * Prints all the posts of every user's friend.
     * 
     */
    void viewFriendsPosts();

    /**
     * Prints all the friends of the user by name.
     * 
     */
    void viewFriends();

    /**
     * Receive a new message into Received Messages.
     * 
     * @param message - The message to be received.
     */
    void receiveMessage(Message* message);

    /**
     * Sends a message to a user.
     * 
     * @param target - the target user.
     * @param message - The message to send.
     */
    virtual void sendMessage(User* target, Message* message);

    /**
     * View all the received messages.
     * 
     */
    void viewReceivedMessages();
};

class BusinessUser: public User
{
    friend class Usocial;

protected:
    BusinessUser();

public:
    /**
     * Sends a message to a user.
     * 
     * @param user - The user who suppuse to get the message.
     * @param message - The message that should be send.
     */
    void sendMessage(User* user, Message* message);
};

#endif /* USER_H_ */