#ifndef ONLINE_READER_H
#define ONLINE_READER_H
#include "Headers.h"
#include "Menu.h"
#include "Site.h"


class Online_Reader {
public:
    void run();

private:
    Menu menu;
    Site site;
};


#endif //ONLINE_READER_H
