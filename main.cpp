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
string braceletOrders[NUM_BRACELETS] = {"Friendship Band", "Charm Bracelet", "Beaded Bracelet", "Leather Bracelet", "Ribbon Bracelet"};
string candyOrders[NUM_CANDIES] = {"Gummy Bears", "Chocolate Bar", "Lollipop", "Skittles", "Marshmallows"};

CoffeeNode* createNode(string name, string order) {
    CoffeeNode* newNode = new CoffeeNode();
    newNode->customerName = name;
    newNode->drinkOrder = order;
    newNode->next = nullptr;
    return newNode;
}

void enqueue(CoffeeNode*& head, string name, string order) {
    CoffeeNode* newNode = creatNode(name, order);
    if (!head) {
        head= newNode;
    } else {
        CoffeeNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void dequeue(CoffeeNode*& head) {
    if (head) {
        CoffeeNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void displayCoffeeBooth(CoffeeNode* head) {
    if (!head) {
        cout << "Coffee Booth: No customers in queue.\n";
    } else {
        cout << "Coffee Booth Queue: ";
        CoffeeNode* temp = head;
        while (temp) {
            cout << temp->customerName << " (" << temp->drinkOrder << ") ";
            temp = temp->next;