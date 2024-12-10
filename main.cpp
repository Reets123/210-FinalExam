// FinalExam #1
// COMSC-210 - Ibrahim Alatig 

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <vector>

using namespace std;

// Struct for Coffee Booth Node
struct CoffeeNode {
    string customerName;
    string drinkOrder;
    CoffeeNode* next;
};