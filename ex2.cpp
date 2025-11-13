//Queue Simulation - Customer Line

#include <iostream>
#include <queue>
using namespace std;

class CustomerQueue {
private:
    queue<int> customers;
    int nextCustomerID;

public:
    CustomerQueue() : nextCustomerID(1) {}
    
    void enqueue() {
        customers.push(nextCustomerID);
        cout << "Customer " << nextCustomerID << " joined the queue." << endl;
        nextCustomerID++;
        displayQueue();
    }
    
    void dequeue() {
        if (customers.empty()) {
            cout << "No customers in queue!" << endl;
            return;
        }
        cout << "Customer " << customers.front() << " served." << endl;
        customers.pop();
        displayQueue();
    }
    
    void displayQueue() {
        if (customers.empty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        
        queue<int> temp = customers;
        cout << "Current queue: ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    CustomerQueue cq;
    
    cq.enqueue(); // Customer 1
    cq.enqueue(); // Customer 2
    cq.enqueue(); // Customer 3
    cq.dequeue(); // Serve Customer 1
    cq.enqueue(); // Customer 4
    cq.dequeue(); // Serve Customer 2
    
    return 0;
}