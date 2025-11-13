#include <iostream>
#include <stack>
using namespace std;

class BrowserHistory {
private:
    stack<string> backStack;
    stack<string> forwardStack;
    string currentPage;

public:
    BrowserHistory() {
        currentPage = "Home Page";
    }
    
    void visit(string url) {
        backStack.push(currentPage);
        currentPage = url;
        // Clear forward stack when visiting new page
        while (!forwardStack.empty()) {
            forwardStack.pop();
        }
        cout << "Visited: " << url << endl;
    }
    
    void back() {
        if (backStack.empty()) {
            cout << "Cannot go back!" << endl;
            return;
        }
        forwardStack.push(currentPage);
        currentPage = backStack.top();
        backStack.pop();
        cout << "Back to: " << currentPage << endl;
    }
    
    void forward() {
        if (forwardStack.empty()) {
            cout << "Cannot go forward!" << endl;
            return;
        }
        backStack.push(currentPage);
        currentPage = forwardStack.top();
        forwardStack.pop();
        cout << "Forward to: " << currentPage << endl;
    }
    
    void displayCurrent() {
        cout << "Current page: " << currentPage << endl;
    }
};

int main() {
    BrowserHistory bh;
    
    bh.visit("google.com");
    bh.visit("facebook.com");
    bh.visit("youtube.com");
    bh.back();
    bh.back();
    bh.forward();
    bh.visit("github.com");
    bh.forward(); // Should not work
    
    return 0;
}