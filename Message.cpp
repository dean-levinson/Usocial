#include <string>
#include <list>
#include "Message.h"

Message::Message(string text): text(text) {}

string Message::getText() {
    return text;
}

void Message::add_author(const string author) {
    text.insert(0, author + ": ");
}
