// Stack Implement using Linked List
/*
push, pop, isEmpty, print, size,peek(top)
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
   

    Node(int value) : data(value), next(nullptr) {}
};

void push (Node*& Top, int value, int& size) {
  Node* newNode = new Node(value);
  newNode -> next = Top;
  Top = newNode;

  cout << value << " Top is Added Successfully" << endl;
  
  size++;
  
}

void pop(Node*& Top, int& size) {
    if (Top == nullptr) {
        cout << "Stack Underflow!\n";
        return;
    }
    Node* temp = Top;
    Top = Top->next;
    cout << temp->data << " popped from stack.\n";
    delete temp;
    size--;
}


bool isEmpty(Node* Top){
  return Top == nullptr;
}

void print(Node* Top) {
    if (Top == nullptr) {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Stack from top to bottom: ";
    Node* temp = Top;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void size(Node* Top) {
    if (Top == nullptr) {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Stack from top to bottom: ";
    Node* temp = Top;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void Peek(Node* Top) {
    if (Top == nullptr) {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Top element is: " << Top->data << endl;
}



int main(){
    Node* Top = nullptr;
    int size = 0;
    
    push(Top, 10 , size);
    push(Top, 20, size);
    push(Top, 30, size);
    
    pop(Top, size);
    
    
    print(Top);
    
        if (isEmpty(Top)) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Stack is not empty.\n";
    }
    
    cout << "Current Stack Size: " << size << endl;
    
}


// --------------------------------------------------------------------------------------------------------------------------------------------
// Stack implements using Array 

#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;     // array to store stack elements
    int top;      // index of top element
    int capacity; // maximum size of the stack

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1; // stack is initially empty
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed onto stack." << endl;
    }

    // Pop the top element
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop." << endl;
            return;
        }
        cout << arr[top--] << " popped from stack." << endl;
    }

    // Peek the top element
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == capacity - 1;
    }

    // Display stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s(5); // create stack of size 5

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    s.pop();
    s.peek();
    s.display();

    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70); // should show overflow
    s.display();

    return 0;
}
