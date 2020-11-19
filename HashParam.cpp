#include "HashParam.hpp"

HashParam::HashParam()
{
    salt[SALTLEN];
    memset( salt, 0x6a, SALTLEN );
    hashed[HASHLEN];

    // pwdlen = strlen((char *)pwd);

    t_cost = 2;            // 1-pass computation
    m_cost = (1<<16);      // 64 mebibytes memory usage
    parallelism = 1;
}


void HashParam::hash_function(std::string password, int (&out)[HASHLEN])
{
    char pwd[password.length()];
    strcpy(pwd, password.c_str());

    int pwdlen = sizeof(pwd)/sizeof(pwd[0]);

    // std::cout<<"password : ";
    // for(int i = 0 ; i < pwdlen ; i++)
    // {
    //     printf("%c", pwd[i]);
    // }
    // printf("|\n");

    argon2i_hash_raw(t_cost, m_cost, parallelism, pwd, pwdlen, salt, SALTLEN, hashed, HASHLEN);
    std::cout<<"hash : ";
    for(int i=0; i<HASHLEN ; i++)
    {
        printf("%d", hashed[i]);
        out[i] = hashed[i];
    }
    printf("|\n");


}