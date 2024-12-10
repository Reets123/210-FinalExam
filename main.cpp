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
         }
        cout << endl;
    }
}

void simulateMuffinBooth(deque<MuffinCustomer>& muffinQueue) {
    if (!muffinQueue.empty()) {
        cout << "Muffin Booth serving: " << muffinQueue.front().customerName << " (" << muffinQueue.front().muffinOrder << ")" << endl;
        muffinQueue.pop_front();
    }
    if (rand() % 2 == 0) { // 50% chance to add a new customer
        int randomIndex = rand() % NUM_CUSTOMERS;
        MuffinCustomer newCustomer = {customerNames[randomIndex], muffinOrders[rand() % NUM_MUFFINS]};
        muffinQueue.push_back(newCustomer);
        cout << "New customer joined Muffin Booth: " << newCustomer.customerName << " (" << newCustomer.muffinOrder << ")\n";
    }
}

void simulateBraceletBooth(vector<BraceletCustomer>& braceletQueue) {
    if (!braceletQueue.empty()) {
        cout << "Bracelet Booth serving: " << braceletQueue.front().customerName << " (" << braceletQueue.front().braceletOrder << ")" << endl;
        braceletQueue.erase(braceletQueue.begin());
    }
    if (rand() % 2 == 0) { // 50% chance to add a new customer
        int randomIndex = rand() % NUM_CUSTOMERS;
        BraceletCustomer newCustomer = {customerNames[randomIndex], braceletOrders[rand() % NUM_BRACELETS]};
        braceletQueue.push_back(newCustomer);
        cout << "New customer joined Bracelet Booth: " << newCustomer.customerName << " (" << newCustomer.braceletOrder << ")\n";
    }
}

void simulateCandyBooth(CandyCustomer candyQueue[], int& count) {
    if (count > 0) {
        cout << "Candy Booth serving: