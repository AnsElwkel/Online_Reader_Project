#include "header/Backend.h"

void Backend::createAccount(const std::vector<std::string> &information) {
    current_user = information[0];

    fileManager.create_new_account(information);
    fileManager.insert_to_users_file(current_user);
}

void Backend::view_profile() const {
    std::vector<std::string> information = fileManager.get_information_from_user_file(current_user);
    std::cout << "Name: " << information[3] << std::endl
              << "Email: " << information[2] << std::endl
              << "user name: " << information[0] << std::endl;
}

//Check login
bool Backend::valid_login(const std::string &_username, const std::string &_password) {
    if (fileManager.valid_login(_username, _password)) {
        current_user = _username;
        return true;
    }

    return false;
}

//To check login information same as information of admin or not
bool Backend::is_admin(const std::string &username, const std::string &password) {
    if (username == "AnasElwkel")
        return fileManager.valid_login(username, password);
    return false;
}

void Backend::list_from_reading_history() {
    std::vector<std::string> file;
    const std::string fileName = "Files/Accounts/" + current_user;
    std::cout << fileName << std::endl;
    fileManager.load_all_file(file, fileName);
    int i = 0;
    while (file[i] != "__HISTORY__")i++;
    i++;
    while (i < file.size())
        std::cout << i - 1 << ": " << file[i++] << std::endl;
    std::cout << "\nWhich session to open?:" << std::endl
            << "Enter number in range 1 - " << file.size() - 2;
    int choice, page = 1;
    std::cin >> choice;
    std::cout << std::endl;
    std::string book_name = "";
    std::stringstream ss(file[choice + 1]);

    bool flag = false;
    while (!ss.eof()) {
        std::string tmp;
        ss >> tmp;
        if (tmp != "__page" and !flag)
            book_name += tmp + " ";
        else if (tmp == "__page") {
            flag = true;
            book_name.pop_back();
        } else {
            page = std::stoi(tmp);
            break;
        }
    }
    std::cout << book_name << " " << page << std::endl;
    navigate_in_book(book_name, page);
}

void Backend::list_from_available_book() {
    std::vector<std::string> file;
    std::string fileName = "Files/booksOnSite";
    fileManager.load_all_file(file, fileName);
    std::cout << "Our current book collection: " << std::endl;
    for (int i = 0; i < file.size(); i++)
        std::cout << "\t\t" << i + 1 << ": " << file[i] << std::endl;
    std::cout << "\nWhich book to read?:\nEnter number in range 1 - " << file.size() << std::endl;
    int choice;
    std::cin >> choice;

    navigate_in_book(file[choice - 1]);
}

void Backend::show_page(const std::vector<std::string> &book, int page) const noexcept{
    int i = 0;
    while (book[i] != "Page " + std::to_string(page) + ':') i++;
    i++;
    while (i < book.size() and book[i] != "Page " + std::to_string(page + 1) + ':')
        std::cout << book[i++] << std::endl;
}

void Backend::navigate_in_book(const std::string &book_name, int _page) {
    std::vector<std::string> book;
    const std::string fileName = "Files/Books/" + book_name;
    fileManager.load_all_file(book, fileName);
    int total_num_of_pages = stoi(book[0]);
    int page = _page;
    std::cout << "Current Page: " << page << '/' << total_num_of_pages << std::endl;
    show_page(book, page);
    menu.setMenu({
        "Next Page",
        "Previous Page",
        "Stop Reading"
    });

    while (page <= total_num_of_pages) {
        menu.showMenu();
        int op;
        std::cout << "Enter number in range 1 - 3: ";
        std::cin >> op;
        std::cout << std::endl;
        if (op == 1) {
            page++;
            std::cout << "Current Page: " << page << '/' << total_num_of_pages << std::endl;
            show_page(book, page);
        } else if (op == 2) {
            --page;
            std::cout << "Current Page: " << page << '/' << total_num_of_pages << std::endl;
            show_page(book, page);
        } else if (op == 3) {
            fileManager.insert_new_history_to_user(book_name, page, total_num_of_pages, current_user);
            break;
        }
    }
}

// From admin
void Backend::add_book() {
    std::cout << "Enter book name: ";
    std::string book_name;
    std::cin.ignore();
    std::getline(std::cin, book_name);
    std::cout << std::endl;

    if (!fileManager.book_exist(book_name))
        return std::cout << "Book doesn't exist" << std::endl, void();

    fileManager.add_book_to_site(book_name);
}
