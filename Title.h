#ifndef TITLE_H
#define TITLE_H

#include <string>

class Title {
    private:
        std::string title;
    public:
        std::string getTitle();
        void setTitle(std::string);
};

#endif