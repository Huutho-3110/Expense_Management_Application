// Use this header file for including Function and Meaning which will use for all the project
#ifndef wallet_h
#define wallet_h

// Declare the libraries to use
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

// To store the user --> using struct

struct userInfo // This struct will store the user information
{
    std::string name;
    std::string address;
    std::string email;
    int age;
};
struct wallet
{
    std::string type;        // Type of money
    double amount;           // Money spent / earn
    std::string category;    // The money earn from ? / spent for ?
                             // Example: earn from Salary --> category Salary
    std::string description; // Use for note --> when ? with ?
    std::string typeWallet;  // What kind of wallet user use to pay - to earn
};
// Call and name what function will use in the project
void getUser();          // get user information
void setInitialwallet(); // set the initial wallet for user
void addTransaction();   // get transaction (dao dich) spent / earn
void summary();          // summary all the spent and earn for user
double getMoney();
void USER(); // get the amount of money from user --> this function only support for setInitialwallet
#endif

/*
Next to do:
- create a file to build all the fucntion
- create a main project main.cpp

*/