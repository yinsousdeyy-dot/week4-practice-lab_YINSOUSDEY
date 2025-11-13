//Stack Reversing string(word)

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseString(string str) {
    stack<char> s;
    
    // Push all characters onto stack
    for (char c : str) {
        s.push(c);
    }
    
    // Pop characters to get reversed string
    string reversed = "";
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }
    
    return reversed;
}

int main() {
    string input = "HELLO";
    cout << "Input: " << input << endl;
    cout << "Output: " << reverseString(input) << endl;
    return 0;
}