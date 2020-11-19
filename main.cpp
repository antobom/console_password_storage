#include <openssl/aes.h>
#include <iostream>
#include "HomePage.hpp"
// #include "HashParam.hpp"
#include <fstream>
// #include <bits/stdc++.h>

// #define pwd "string"


#define HASHLEN 32
#define SALTLEN 16
#define PASSLEN 16

using namespace std;



int main()
{
    HomePage homePage;
    homePage.welcome_page();
    
}