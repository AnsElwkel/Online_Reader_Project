#ifndef SITE_H
#define SITE_H
#include "Backend.h"
#include "Headers.h"
#include "Menu.h"

//Front end of page
class Site {
public:
    void SignUp();

    void Login();

    void user_menu();

    void admin_menu();

private:
    std::string current_user;
    Menu menu;
    Backend backend;
};


#endif //SITE_H
