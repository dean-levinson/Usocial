#include <iostream>
#include <string>
#include <list>
#include "Media.h"

using namespace std;

Media::~Media() {};

void Photo::display() {
    cout << "Photo";
};

void Audio::display() {
    cout << "Audio";
};

void Video::display() {
    cout << "Video";
};
