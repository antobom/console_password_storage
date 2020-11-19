#ifndef HASHPARAM
#define HASHPARAM

#include <argon2.h>
#include <string.h>
#include <iostream>

#define HASHLEN 32
#define SALTLEN 16
#define PASSLEN 16

class HashParam
{
private:
    uint8_t salt[SALTLEN];

    uint8_t hashed[HASHLEN];

    // uint32_t pwdlen = strlen((char *)pwd);

    uint32_t t_cost;
    uint32_t m_cost; 
    uint32_t parallelism;

public:
    HashParam();
    void hash_function(std::string password, int (&out)[HASHLEN]);


};

#endif