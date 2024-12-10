// FinalExam #1
// COMSC-210 - Ibrahim Alatig 

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <vector>

using namespace std;

// Struct for Coffee Booth 
struct CoffeeNode {
    string customerName;
    string drinkOrder;
    CoffeeNode* next;
};

// Struct for Muffin Booth
struct MuffinCustomer {
    string customerName;
    string muffinOrder;
};

// Struct for Friendship Bracelet 
struct BraceletCustomer {
    string customerName;
    string braceletOrder;
};

// Struct for Candies 
struct CandyCustomer {
    string customerName;
    strin candyOrder;
};