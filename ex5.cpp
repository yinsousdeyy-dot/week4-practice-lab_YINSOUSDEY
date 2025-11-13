#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string expression) {
    stack<char> s;
    
    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) return false;
            
            char top = s.top();
            s.pop();
            
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    
    return s.empty();
}

int main() {
    string expr1 = "(A+B)*(C-D)";
    string expr2 = "((A+B)*C";
    string expr3 = "{(A+B)*[C-D]}";
    string expr4 = "(A+B)*C)";
    
    cout << expr1 << " is " << (isBalanced(expr1) ? "Balanced" : "Unbalanced") << endl;
    cout << expr2 << " is " << (isBalanced(expr2) ? "Balanced" : "Unbalanced") << endl;
    cout << expr3 << " is " << (isBalanced(expr3) ? "Balanced" : "Unbalanced") << endl;
    cout << expr4 << " is " << (isBalanced(expr4) ? "Balanced" : "Unbalanced") << endl;
    
    return 0;
}