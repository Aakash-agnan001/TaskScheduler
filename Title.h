#ifndef TITLE_H
#define TITLE_H

#include <string>

class Title {
    private:
        std::string title;
    public:
        Title(std::string);
        std::string getTitle();
        void setInfo(std::string);
};

#endif
