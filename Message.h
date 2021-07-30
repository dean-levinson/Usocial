#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <string>
#include <list>

using namespace std;

class Message
{
private:
    string text;
    
public:
    Message(string text);

    /**
     * Returns the text of the message.
     */
    string getText();

    /**
     * Adds an author at the begging of the message.
     * 
     * @param author - the name of the message author.
     */
    void add_author(const string author);
};

#endif /* MESSAGE_H_ */