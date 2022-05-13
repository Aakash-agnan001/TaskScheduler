#include "Title.h"

Title::Title(std::string title) {
    this->title = title;
}

std::string Title::getTitle() {
    return this->title;
}

void Title::setTitle(std::string title) {
    this->title = title;
}
