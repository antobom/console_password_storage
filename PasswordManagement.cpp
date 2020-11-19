#include "PasswordManagement.hpp"


PasswordManagement::PasswordManagement()
{

}


void PasswordManagement::new_password(std::string username, std::string password)
{
    //create new password and store it in account file
}

void PasswordManagement::display_password(std::string username, std::string password)
{
    std::ifstream account_file;
    std::string file_content, line;

    account_file.open(username);
    while(std::getline(account_file, line))
    {
        file_content.append(line);
        file_content.append("\n");
    }

    std::cout<<file_content<<std::endl;


}