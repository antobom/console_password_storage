#ifndef PASSWORD_MANAGEMENT
#define PASSWORD_MANAGEMENT


#include <iostream>
#include <fstream>
#include <string>


class PasswordManagement
{
private:
    

public:
    PasswordManagement();
    void new_password(std::string username, std::string password);
    void display_password(std::string username, std::string password);


};

#endif