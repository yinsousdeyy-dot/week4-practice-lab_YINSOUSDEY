#include <iostream>
#include <queue>
using namespace std;

struct PrintJob {
    int jobID;
    int pages;
    
    PrintJob(int id, int p) : jobID(id), pages(p) {}
};

class PrinterQueue {
private:
    queue<PrintJob> jobs;
    int nextJobID;

public:
    PrinterQueue() : nextJobID(1) {}
    
    void addJob(int pages) {
        PrintJob job(nextJobID, pages);
        jobs.push(job);
        cout << "Added Job " << nextJobID << " (" << pages << " pages)" << endl;
        nextJobID++;
        displayQueue();
    }
    
    void processJob() {
        if (jobs.empty()) {
            cout << "No jobs to process!" << endl;
            return;
        }
        
        PrintJob current = jobs.front();
        cout << "Processing Job " << current.jobID << " (" << current.pages << " pages)" << endl;
        jobs.pop();
        displayQueue();
    }
    
    void displayQueue() {
        if (jobs.empty()) {
            cout << "Printer queue is empty." << endl;
            return;
        }
        
        queue<PrintJob> temp = jobs;
        cout << "Current queue: ";
        while (!temp.empty()) {
            cout << "J" << temp.front().jobID << "(" << temp.front().pages << "p) ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    PrinterQueue pq;
    
    pq.addJob(5);
    pq.addJob(3);
    pq.addJob(10);
    pq.processJob();
    pq.addJob(2);
    pq.processJob();
    pq.processJob();
    pq.processJob();
    
    return 0;
}