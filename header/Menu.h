#ifndef MENU_H
#define MENU_H
#include "Headers.h"

class Menu {
    std::vector<std::string> menu;

public:
    void showMenu() const noexcept;

    void setMenu(const std::vector<std::string> &menu);
};


#endif //MENU_H
