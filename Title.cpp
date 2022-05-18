#include "Title.h"

Title::Title(std::string title) {
    this->title = title;
}

std::string Title::getInfo(std::string marker) {
    return this->title;
}

void Title::setInfo(std::string title) {
    this->title = title;
}
