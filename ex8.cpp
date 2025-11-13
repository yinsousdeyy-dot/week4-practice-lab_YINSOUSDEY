#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Patient {
    int id;
    string name;
    int priority; // 1 = Critical, 2 = Serious, 3 = Stable
    
    Patient(int i, string n, int p) : id(i), name(n), priority(p) {}
    
    // Overload < operator for priority queue
    bool operator<(const Patient& other) const {
        return priority > other.priority; // Lower number = higher priority
    }
};

class EmergencyRoom {
private:
    priority_queue<Patient> patients;
    int nextPatientID;

public:
    EmergencyRoom() : nextPatientID(1) {}
    
    void addPatient(string name, int priority) {
        Patient patient(nextPatientID, name, priority);
        patients.push(patient);
        cout << "Added patient: " << name << " (Priority: " << priority << ")" << endl;
        nextPatientID++;
        displayQueue();
    }
    
    void servePatient() {
        if (patients.empty()) {
            cout << "No patients waiting!" << endl;
            return;
        }
        
        Patient current = patients.top();
        patients.pop();
        cout << "Serving patient: " << current.name << " (ID: " << current.id 
             << ", Priority: " << current.priority << ")" << endl;
        displayQueue();
    }
    
    void displayQueue() {
        if (patients.empty()) {
            cout << "No patients in emergency room." << endl;
            return;
        }
        
        // Create temporary copy to display
        priority_queue<Patient> temp = patients;
        cout << "Current queue (by priority): ";
        while (!temp.empty()) {
            cout << temp.top().name << "(P" << temp.top().priority << ") ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    EmergencyRoom er;
    
    er.addPatient("John", 2);  // Serious
    er.addPatient("Alice", 1); // Critical
    er.addPatient("Bob", 3);   // Stable
    er.addPatient("Carol", 1); // Critical
    
    er.servePatient(); // Should serve Alice (Critical)
    er.servePatient(); // Should serve Carol (Critical)
    er.servePatient(); // Should serve John (Serious)
    er.servePatient(); // Should serve Bob (Stable)
    
    return 0;
}