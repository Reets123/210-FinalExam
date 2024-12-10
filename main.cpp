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
    CoffeeNode* newNode = createNode(name, order);
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
        cout << "Candy Booth serving:" << candyQueue[0].customerName << " (" << candyQueue[0].candyOrder << ")" << endl;
        for (int i = 1; i < count; ++i) {
            candyQueue[i - 1] = candyQueue[i]; 
        }
        count--;
    }
    if (rand() % 2 == 0) { // 50% chance fro new customer
        if (count < NUM_CANDIES) {
            int randomIndex = rand() % NUM_CUSTOMERS;
            candyQueue[count++] = {customerNames[randomIndex], candyOrders[rand() % NUM_CANDIES]};
            cout << "New customer joined Candy Booth: " << candyQueue[count - 1].customerName << " (" << candyQueue[count - 1].candyOrder << ")\n";
        } else {
            cout << "Candy Booth is full.\n";
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    CoffeeNode* coffeeBoothQueue = nullptr;
    for (int i = 0; i < 3; ++i) { // 3 customers
        enqueue(coffeeBoothQueue, customerNames[rand() % NUM_CUSTOMERS], drinkOrders[rand() % NUM_CUSTOMERS]);
    }

    deque<MuffinCustomer> muffinQueue;
    vector<BraceletCustomer> braceletQueue;
    CandyCustomer candyQueue[NUM_CANDIES];
    int candyCount = 0;

    for (int round = 1; round <= 10; ++round) {
        cout << "Round " << round << ":\n";

        if (coffeeBoothQueue) {
            cout << "Coffee Booth serving: " << coffeeBoothQueue->customerName << " (" << coffeeBoothQueue->drinkOrder << ")" << endl;
            dequeue(coffeeBoothQueue);
        } else {
            cout << "Coffee Booth: No customers to serve.\n";
        }
        if (rand() % 2 == 0) { // 50% chance
            enqueue(coffeeBoothQueue, customerNames[rand() % NUM_CUSTOMERS], drinkOrders[rand() % NUM_CUSTOMERS]);
            cout << "New customer joined Coffee Booth.\n";
        }

        // Muffin Booth
        simulateMuffinBooth(muffinQueue);

        // Bracelet Booth
        simulateBraceletBooth(braceletQueue);

        // Candy Booth
        simulateCandyBooth(candyQueue, candyCount);

        // Display queues
        displayCoffeeBooth(coffeeBoothQueue);
        cout << "Current Muffin Booth queue size: " << muffinQueue.size() << endl;
        cout << "Current Bracelet Booth queue size: " << braceletQueue.size() << endl;
        cout << "Current Candy Booth queue size: " << candyCount << endl;

        cout << "------------------------------------------\n";
    }

    // Clean up 
    while (coffeeBoothQueue) {
        dequeue(coffeeBoothQueue);
    }

    return 0;
}