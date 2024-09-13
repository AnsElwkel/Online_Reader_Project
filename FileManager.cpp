#include "header/FileManager.h"

void FileManager::create_new_account(const std::vector<std::string> &information) noexcept {
    const std::string fileName = "Files/Accounts/" + information[0];
    std::ofstream fout(fileName);
    fout << information[0] << ' ' << information[1] << ' ' << information[2] << ' ' << information[3] << std::endl;
    fout << "__HISTORY__" << std::endl;
    fout.close();
}

void FileManager::insert_to_users_file(const std::string &username) const noexcept {
    const std::string fileName = "Files/users";
    std::ofstream fout(fileName, std::ios::out | std::ios::app);
    fout << username << std::endl;
    fout.close();
}

std::vector<std::string> FileManager::get_information_from_user_file(const std::string &username) const {
    const std::string fileName = "Files/Accounts/" + username;
    std::ifstream fin(fileName);
    if (fin.fail())
        throw std::runtime_error("File not found -> get_information_from_user_file");
    std::string line, user_name, name, email, password;
    std::getline(fin, line);
    std::stringstream ss(line);
    ss >> user_name >> password >> email >> name;
    fin.close();
    return {user_name, password, email, name};
}

bool FileManager::valid_login(const std::string &_username, const std::string &_password) const noexcept {
    const std::string fileName = "Files/Accounts/" + _username;
    std::string line, username, email, pass, name;
    std::ifstream fin(fileName);
    if (fin.fail())
        return false;
    getline(fin, line);
    std::stringstream ss(line);
    ss >> username >> pass >> email >> name;
    if (pass == _password) {
        return true;
    }

    return false;
}

void FileManager::load_all_file(std::vector<std::string> &container, const std::string &fileName) {
    std::ifstream fin(fileName);
    if (fin.fail())
        throw std::invalid_argument("File not found -> load all file function");
    std::string line;
    while (getline(fin, line)) {
        container.push_back(line);
    }
    fin.close();
}

void FileManager::insert_new_history_to_user(const std::string &book_name, int page, int total_num_of_pages,
                                             std::string user) {
    const std::string fileName = "Files/Accounts/" + user;
    std::ofstream fout(fileName, std::ios::out | std::ios::app);
    fout << book_name << " __page " << page << " /" << total_num_of_pages << " " << std::endl;
    fout.close();
}

bool FileManager::book_exist(const std::string &book_name) const {
    const std::string fileName = "Files/booksOnGoogle";
    std::ifstream fin(fileName);
    if (fin.fail())
        throw std::invalid_argument("File not found -> book exist");

    std::string line;
    while (getline(fin, line)) {
        if (line == book_name) {
            fin.close();
            return true;
        }
    }
    fin.close();

    return false;
}

void FileManager::add_book_to_site(const std::string &book_name) noexcept {
    const std::string fileName = "Files/booksOnSite";
    std::ofstream fout(fileName, std::ios::out | std::ios::app);
    fout << book_name << std::endl;
    fout.close();
}
