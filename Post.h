#ifndef POST_H_
#define POST_H_

#include <string>
#include <list>
#include <iostream>
#include "Media.h"

using namespace std;

class Post
{
private:
    string text;
    Media* media;

public:
    Post(string);
    Post(string, Media*);
    ~Post();

    /**
     * Returns the text of the post.
     */
    string getText();

    /**
     * Returns the a pointer to the media of the post.
     */
    Media* getMedia();
};

/**
 * Overloads << operation for post object.
 * 
 * @param os  Ostream object.
 * @param post The post to print.
 * @return The ostream object.
 */
ostream& operator<<(ostream& os, Post& post);


#endif /* POST_H_ */