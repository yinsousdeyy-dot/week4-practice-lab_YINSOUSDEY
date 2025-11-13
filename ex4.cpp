#include <iostream>
#include <queue>
using namespace std;

class BankQueue {
private:
    queue<int> customers;
    int customerCount;

public:
    BankQueue() : customerCount(0) {}
    
    void addCustomer() {
        customerCount++;
        customers.push(customerCount);
        cout << "Customer " << customerCount << " arrived." << endl;
        displayQueue();
    }
    
    void serveCustomer() {
        if (customers.empty()) {
            cout << "No customers to serve!" << endl;
            return;
        }
        cout << "Serving customer " << customers.front() << endl;
        customers.pop();
        displayQueue();
    }
    
    void displayQueue() {
        if (customers.empty()) {
            cout << "No customers waiting." << endl;
            return;
        }
        
        queue<int> temp = customers;
        cout << "Customers waiting: ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    BankQueue bq;
    
    bq.addCustomer();
    bq.addCustomer();
    bq.serveCustomer();
    bq.addCustomer();
    bq.serveCustomer();
    bq.serveCustomer();
    bq.serveCustomer(); // Should show empty message
    
    return 0;
}