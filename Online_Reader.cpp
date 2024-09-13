#include "header/Online_Reader.h"

void Online_Reader::run() {
    menu.setMenu({"Login",
                "Sign Up"});
    menu.showMenu();
    std::cout << "\nEnter number in range 1 - 2 : ";

    int choice;
    std::cin >> choice;
    std::cout << std::endl;
    if (choice == 1)
        site.Login();
    else if (choice == 2)
        site.SignUp();
}
