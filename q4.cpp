#include <iostream>
using namespace std;
class Stack {
private:
    int* arr;
    int top;
    int size;

public:
    
    Stack(int s = 5) {
        size = s;
        arr = new int[size];
        top = -1; 
    }
    
    ~Stack() {
        delete[] arr;
    }
    
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full, Cannot push value." <<endl;
            return;
        }
        else
        arr[++top] = value;
        cout << "Value " << value << " pushed onto the stack." <<endl;
    }
    
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty, Cannot pop value." << endl;
            return;
        }
        cout << "Value " << arr[top--] << " popped from the stack." << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Peek operation failed." << endl;
            return -1; 
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }
    
    void print() {
        if (isEmpty()) {
            cout << "Stack is empty." <<endl;
            return;
        }
        cout << "Stack values: ";
        for (int i = 0; i <= top; ++i) {
            cout << arr[i] << " ";
        }
        cout <<endl;
    }
};

int main() {
    int choice, values;
    int size;
    cout << "Enter size of stack (default is 5): ";
    cin >> size;

    Stack stack(size);

    do {
        cout << "\nStack Menu\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Print Stack\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> values;
                stack.push(values);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cout << "Top value: " << stack.peek() <<endl;
                break;
            case 4:
                if (stack.isEmpty())
                    cout << "Stack is empty." <<endl;
                else
                    cout << "Stack is not empty." <<endl;
                break;
            case 5:
                if (stack.isFull())
                    cout << "Stack is full." <<endl;
                else
                    cout << "Stack is not full." <<endl;
                break;
            case 6:
                stack.print();
                break;
            case 7:
                cout << "Thank you for using this app.." <<endl;
                break;
            default:
                cout << "Invalid choice." <<endl;
        }
    } while (choice != 7);

    return 0;
