// You are building a very small text editor that only supports appending words to a document, but
// it still has to feel like a real editor when the user makes a mistake. Every time the user calls type(word),
// that word is appended to the end of the document. The user can call undo() at any time to reverse the
// most recent typing action, and redo() to bring back an action that was just undone. The catch is that once
// the user types something new after an undo, every action that could have been redone is permanently
// lost exactly like undo/redo works in a real editor such as Word or VS Code, you cannot redo into a
// history branch that no longer exists once new history has been written over it.

// For example, calling type(Hello) and then type(World) leaves the document as Hello World;
// calling undo() removes World, leaving Hello; calling redo() restores it to Hello World;
// calling undo() again returns to Hello; but if the user now calls type(There),the document becomes Hello There
// and any further call to redo() must do nothing, because the World branch of history has been erased by the new action.

// Your Task (C++): Implement this as a C++ class with type(string), undo(), redo(), and print() methods,
// using two stacks to manage the undo and redo history. Write a main() that reproduces the exact sequence
// of calls above and prints the document state after each call.

#include <iostream>
using namespace std;

#define MAX 250

class Stack
{
public:
    int top;
    string array[MAX];

    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top < 0;
    }

    bool isFull()
    {
        return top >= MAX - 1;
    }

    void push(string word)
    {
        if (!isFull())
            array[++top] = word;
    }

    string pop()
    {
        if (!isEmpty())
        {
            return array[top--];
        }
        return " ";
    }
};

class TextEditor
{
    Stack undoStack;
    Stack redoStack;
    string document;

public:
    void type(string word)
    {
        document += word + " ";
        undoStack.push(word);

        while (!redoStack.isEmpty())
            redoStack.pop();
    }
    void undo()
    {
        if (undoStack.isEmpty())
            return;

        string word = undoStack.pop();
        redoStack.push(word);

        for (int i = 0; i < word.length() + 1; i++)
        {
            document.pop_back();
        }
    }

    void redo()
    {
        if (redoStack.isEmpty())
            return;
        string word = redoStack.pop();
        undoStack.push(word);
        document += word + " ";
    }

    void print()
    {
        cout << document << endl;
    }
};

int main(){
    TextEditor editor;

    editor.type("Hello");
    editor.type("World");
    editor.print();

    editor.undo();
    editor.print();

    editor.redo();
    editor.print();

    editor.undo();
    editor.print();

    editor.type("There");
    editor.print();

    editor.redo();
    editor.print();
}