#ifndef MEDIA_H_
#define MEDIA_H_

#include <string>
#include <list>

using namespace std;

class Media
{
public:
    virtual ~Media();

    /**
     * Prints the media.
     */
    virtual void display() = 0;
};

class Photo: public Media
{
public:
    void display();
};

class Audio: public Media
{
public:
    void display();
};

class Video: public Media
{
public:
    void display();
};

#endif /* MEDIA_H_ */