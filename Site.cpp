#include "header/Site.h"

void Site::SignUp() {
    std::string username, password, email, name;

    std::cout << "Enter user name: ";
    std::cin >> username;
    std::cout << "\nEnter password: ";
    std::cin >> password;
    std::cout << "\nEnter name: ";
    std::cin >> name;
    std::cout << "\nEnter email: ";
    std::cin >> email;

    current_user = username;
    backend.createAccount(std::vector<std::string>({username, password, email, name}));
    std::cout << "Hello " << name << "| User View";
    user_menu();
}

void Site::Login() {
    std::string username, password;
    std::cout << "Enter user name: ";
    std::cin >> username;
    std::cout << "\nEnter password: ";
    std::cin >> password;
    while (!backend.valid_login(username, password)) {
        std::cout << "Wrong username or password, please try again.\n";
        std::cout << "Enter user name: ";
        std::cin >> username;
        std::cout << "\nEnter password: ";
        std::cin >> password;
    }
    current_user = username;
    if (backend.is_admin(username, password)) {
        std::cout << "Hello " << current_user << "| Admin View";
        admin_menu();
    } else {
        std::cout << "Hello " << current_user << "| User View";
        user_menu();
    }
}

void Site::user_menu() {
    int op = 0;
    while (op != 4) {
        menu.setMenu({
            "View Profile",
            "List & Select from My Reading History",
            "List & Select from Available Books",
            "Logout"
        });
        menu.showMenu();
        std::cout << "Enter number in range 1 - 4: ";
        std::cin >> op;
        std::cout << std::endl;

        if (op == 1) {
            backend.view_profile();
        } else if (op == 2) {
            backend.list_from_reading_history();
        } else if (op == 3) {
            backend.list_from_available_book();
        }
    }
}

void Site::admin_menu() {
    int op = 0;
    while (op != 3) {
        menu.setMenu({
            "View Profile",
            "Add Books",
            "Logout"
        });
        menu.showMenu();
        std::cout << "Enter number in range 1 - 3: ";
        std::cin >> op;
        std::cout << std::endl;

        if (op == 1) {
            backend.view_profile();
        } else if (op == 2) {
            backend.add_book();
        }
    }
}
