#ifndef BACKEND_H
#define BACKEND_H
#include "Headers.h"
#include "FileManager.h"
#include "Menu.h"

class Backend {
public:
    void createAccount(const std::vector<std::string> &information);

    void view_profile() const;

    bool valid_login(const std::string &username, const std::string &password);

    bool is_admin(const std::string &username, const std::string &password);

    void list_from_reading_history();

    void list_from_available_book();

    void show_page(const std::vector<std::string> &book, int page) const noexcept;

    void navigate_in_book(const std::string &book_name, int page = 1);

    void add_book();

private:
    std::string current_user;
    FileManager fileManager;
    Menu menu;
};


#endif //BACKEND_H
