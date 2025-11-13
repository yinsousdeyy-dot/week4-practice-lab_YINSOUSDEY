#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TextEditor {
private:
    stack<string> undoStack;
    stack<string> redoStack;
    string currentText;

public:
    TextEditor() {
        currentText = "";
    }
    
    void type(string text) {
        undoStack.push(currentText);
        currentText += text;
        // Clear redo stack when new action is performed
        while (!redoStack.empty()) {
            redoStack.pop();
        }
        cout << "Typed: " << text << endl;
        cout << "Current text: " << currentText << endl;
    }
    
    void undo() {
        if (undoStack.empty()) {
            cout << "Nothing to undo!" << endl;
            return;
        }
        redoStack.push(currentText);
        currentText = undoStack.top();
        undoStack.pop();
        cout << "Undo performed." << endl;
        cout << "Current text: " << currentText << endl;
    }
    
    void redo() {
        if (redoStack.empty()) {
            cout << "Nothing to redo!" << endl;
            return;
        }
        undoStack.push(currentText);
        currentText = redoStack.top();
        redoStack.pop();
        cout << "Redo performed." << endl;
        cout << "Current text: " << currentText << endl;
    }
};

int main() {
    TextEditor editor;
    
    editor.type("Hello ");
    editor.type("World");
    editor.undo();
    editor.type("Everyone");
    editor.undo();
    editor.redo();
    
    return 0;
}