#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "Headers.h"


class FileManager {
public:
    void create_new_account(const std::vector<std::string> &information) noexcept;

    void insert_to_users_file(const std::string &username) const noexcept;

    bool valid_login(const std::string &_username, const std::string &_password) const noexcept;

    void load_all_file(std::vector<std::string> &container, const std::string &fileName);

    std::vector<std::string> get_information_from_user_file(const std::string &username) const;

    void insert_new_history_to_user(const std::string &book_name, int page, int total_num_of_pages, std::string user);

    bool book_exist(const std::string &book_name) const;

    void add_book_to_site(const std::string &book_name) noexcept;
};


#endif //FILEMANAGER_H
