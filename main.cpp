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

// the number of different items each will have
const int NUM_CUSTOMERS = 5; 
const int NUM_MUFFINS = 5;    
const int NUM_BRACELETS = 5;  
const int NUM_CANDIES = 5;   

string customerNames[NUM_CUSTOMERS] = {"Alice", "Fred", "Cade", "Rex", "Ethan"};
string drinkOrders[NUM_CUSTOMERS] = {"Latte", "Espresso", "Cappuccino", "Mocha", "Americano"};
string muffinOrders[NUM_MUFFINS] = {"Chocolate Muffin", "Blueberry Muffin", "Banana Muffin", "Red velvet Muffin", "Pumpkin Muffin"};
string braceletOrders[NUM_BRACELET