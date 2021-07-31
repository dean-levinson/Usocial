#include "USocial.h"
#include "User.h"
#include <exception>
#include <iostream>

int main()
{
    Usocial us;
    User* u1 = us.registerUser("Liron");
    User* u2 = us.registerUser("Yahav");
    User* u3 = us.registerUser("Shachaf");
    User* u4 = us.registerUser("Tsur", true);
    User* u5 = us.registerUser("Elit");

    u1->post("Hello world!");
    u2->post("I'm having a great time here :)", new Audio());
    u3->post("This is awesome!", new Photo());

    u5->addFriend(u1);
    u5->addFriend(u2);

    std::cout << "Should be True: " << u5->isFriend(u1) << std::endl;
    std::cout << "Should be False: " << u5->isFriend(u4) << std::endl;

    u5->viewFriendsPosts(); // should see only u1, u2 s' posts
    u4->sendMessage(u5, new Message("Buy Falafel!"));
    u5->viewReceivedMessages();

    // Test removeFriend
    try {
        u5->removeFriend(u3);
    }
    catch (const std::exception& e) {
        std::cout << "error: " << e.what() << std::endl;
    }
    
    // Test addFriend
    try {
        u5->addFriend(u1);
    }
    catch (const std::exception& e) {
        std::cout << "error: " << e.what() << std::endl;
    }

    // Test getUserById
    try {
        us.getUserById(100);
    } catch (const std::exception& e) {
        std::cout << "error: " << e.what() << std::endl;
    }
    
    // Test RemoveUser
    us.removeUser(u1);
    std::cout << "Liron shouldn't be in the friends list:" << std::endl;
    u5->viewFriends();


    u5->viewReceivedMessages();
    u3->addFriend(u5);
    u3->sendMessage(u5, new Message("All your base are belong to us"));
    u5->viewReceivedMessages();

    return 0;
}
