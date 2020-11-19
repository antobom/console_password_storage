#ifndef HOME_PAGE
#define HOME_PAGE

#include <iostream>
#include <fstream>
#include <unistd.h>

#include "HashParam.hpp"
#include "PasswordManagement.hpp"


class HomePage
{
private:
    std::string pwd;
    std::string username;
    std::ofstream account_file;
    HashParam hashParam;
    PasswordManagement passwordManagement;

public:
    HomePage();
    void welcome_page();
    void create_account();
    void open_account();


};

#endif