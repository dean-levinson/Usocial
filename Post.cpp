#include <iostream>
#include <string>
#include <list>
#include "Post.h"

Post::Post(string text): text(text), media(nullptr) {}

Post::Post(string text, Media* media): text(text), media(media) {}

Post::~Post() {
    // Deletes the inside media object if exists
    if (media != nullptr) {
        delete media;
        media = nullptr;
    }
}

string Post::getText() const {
    return text;
}

Media* Post::getMedia() const {
    return media;
}

ostream& operator<<(ostream& os, const Post& post) {
    os << post.getText();
    if (post.getMedia() != nullptr) {
        os << " [";
        post.getMedia()->display();
        os << "]";
    };
    return os;
}
