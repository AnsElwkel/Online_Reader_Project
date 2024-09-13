#include "header/Menu.h"

void Menu::showMenu() const noexcept {
    std::cout << "Menu:" <<std::endl;
    for (int i = 0; i < menu.size(); i++)
        std::cout << "\t\t" << i + 1 << ": " << menu[i] << std::endl;
}

void Menu::setMenu(const std::vector<std::string>& menu) {
    this->menu = menu;
}
