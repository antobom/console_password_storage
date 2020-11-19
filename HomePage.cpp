#include "HomePage.hpp"

HomePage::HomePage()
{

}


void HomePage::create_account()
{
    int hash[HASHLEN];
    std::string username;
    printf("Welcome, enter your new user name : \n");
    std::cin>>username;
    printf("\nEnter your new password :\n");
    std::cin>>pwd;

    // char password[pwd.length()];
    // strcpy(password, pwd.c_str());

    account_file.open(username);
    hashParam.hash_function(pwd, hash);
    for(int i:hash)
    {
        account_file<<i;
    }
    account_file<<std::endl;

    printf("account created !\n");



}


void HomePage::open_account()
{
    bool login_ok = false;
    std::string line;
    int hash[HASHLEN];
    std::string hash_string;
    do
    {
        printf("enter your username : ");
        std::cin>>username;
        printf("enter your password : ");
        std::cin>>pwd;
        // std::cout<<access(username.c_str(), F_OK)<<std::endl;
        if(access(username.c_str(), F_OK)!=-1)
        {
            hashParam.hash_function(pwd, hash);
            for(int i:hash)
                hash_string.append(std::to_string(i));
            // std::cout<<hash_string<<std::endl;

            std::ifstream account_file(username);
            std::getline(account_file, line);
            // std::cout<<line<<std::endl<<hash_string<<std::endl;
            if(line==hash_string)
                login_ok = true;
            else
                printf("password wrong try again\n");
        }
        else
            printf("wrong username");
    }while(!login_ok);

    printf("password ok !\n");

    int choice;
    //call the management class function
    printf("\n1-display password\n2-add a new password\nyour choice: ");
    std::cin>>choice;

    if(choice==1)
        passwordManagement.display_password(username, pwd);
    else if(choice==2)
        passwordManagement.new_password(username, pwd);
    
    
}

void HomePage::welcome_page()
{
    int choice;
    printf("Hi, welcome to PasswordStorage");
    while(1)
    {
        do
        {
            printf("what do you want to do ? \n1-create a new account \n2-login\n3-leave\nYour choice : ");
            std::cin>>choice;
        }while (!(choice==1||choice==2||choice==3));//(choice!=1 || choice ==2) && (choice==1 || choice!=2));
        
        if(choice == 1)
            create_account();
        else if(choice==2)
            open_account();
        else if(choice==3)
            break;
    }
}