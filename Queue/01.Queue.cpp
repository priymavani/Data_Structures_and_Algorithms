// Queue Implementation using Linked List

/*
enqueue, dequeue, isEmpty, size
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
   

    Node(int value) : data(value), next(nullptr) {}
};



void enqueue(Node*& front, Node*& rear, int value) {
    Node* newNode = new Node(value);
    if (rear == nullptr) {
        
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << value << " enqueued into queue.\n";
}

void dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) {
        cout << "Queue is empty.\n";
        return;
    }
    Node* temp = front;
    front = front->next;

    if (front == nullptr) {
        rear = nullptr; 
    }

    cout << temp->data << " dequeued from queue.\n";
    delete temp;
}

void isEmpty(Node* front) {
    if (front == nullptr) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Queue is not empty.\n";
    }
}

void size(Node* front) {
    int count = 0;
    Node* temp = front;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    cout << "Queue size: " << count << endl;
}




int main(){
    Node* front = nullptr;
    Node* rear = nullptr;
    
    enqueue(front, rear, 20);
    enqueue(front, rear, 30);
    enqueue(front, rear,40);
    dequeue(front, rear);
    dequeue(front, rear);
    isEmpty(front);
    size(front);
    
      
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------
// Queue Implementation using Array

#include <iostream>
using namespace std;

class Queue {
private:
    int front;
    int rear;
    int size;
    int* arr;

public:
    // Constructor
    Queue(int capacity) {
        size = capacity;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Check if the queue is full
    bool isFull() {
        return (rear == size - 1);
    }

    // Enqueue: Add an element to the rear
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }

        if (front == -1) front = 0; // first insertion
        arr[++rear] = value;
        cout << value << " enqueued to queue." << endl;
    }

    // Dequeue: Remove an element from the front
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Nothing to dequeue." << endl;
            return;
        }

        cout << arr[front] << " dequeued from queue." << endl;
        front++;

        // Reset indices when queue becomes empty
        if (front > rear) {
            front = rear = -1;
        }
    }

    // Peek: Get the front element
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Main function to test the Queue
int main() {
    Queue q(5); // queue of size 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.peek();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // should show overflow
    q.display();

    return 0;
}
