#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> undo, redo;
    int ch; // necessary define outside do while loop
    string action;

    do {
        cout << "\n1.Do Action  2.Undo  3.Redo  4.Exit\nChoice: ";
        cin >> ch;

        if(ch == 1) {
            cout << "Enter Action: ";
            cin >> action;
            undo.push(action);
            while(!redo.empty()) redo.pop();
            cout << "Action Done.\n";
        }

        else if(ch == 2) {
            if(!undo.empty()) {
                redo.push(undo.top());
                cout << "Undo: " << undo.top() << endl;
                undo.pop();
            } else cout << "Nothing to Undo.\n";
        }

        else if(ch == 3) {
            if(!redo.empty()) {
                undo.push(redo.top());
                cout << "Redo: " << redo.top() << endl;
                redo.pop();
            } else cout << "Nothing to Redo.\n";
        }

    } while(ch != 4);

    return 0;
}

/*
Algorithm

1. Start the program.
2. Create two stacks: **undo** and **redo**.
3. Display menu: Do Action, Undo, Redo, Exit.
4. Read user choice.

**If Do Action:**
5. Read action and push it into undo stack.
6. Clear redo stack.

**If Undo:**
7. If undo stack is not empty,

* Pop top element from undo
* Push it into redo
* Display "Undo".

8. Else show "Nothing to undo".

**If Redo:**
9. If redo stack is not empty,

* Pop top element from redo
* Push it back to undo
* Display "Redo".

10. Else show "Nothing to redo".

11. Repeat menu until Exit.

12. Stop.


*/