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
#include <vector>
using namespace std;

class Queue{
  private:
  vector<int> queue;
  int maxSize;
  int front;
  int rear;
  
  public:
  Queue(int size){
    queue.resize(size);
    maxSize = size;
    front = -1;
    rear = -1;
  }
  
/*1. INSERT (Enqueue)
Purpose: Add a new element to the rear (end) of the queue.

Algorithm Steps:
Check for Overflow Condition: The queue is full if rear == maxSize - 1 (no more space).
Initial Queue Check: If queue is empty (front == -1), initialize front = 0 (first element).
Increment rear: Move rear forward by one to the next empty position.
Insert the new element: Place data at queue[rear].
Confirm the insertion to user or error if full.

  */
  
  void enqueue(int value){
    if(rear == maxSize-1){
      cout << "Queue Overflow! Cannot insert " << value << endl;
      return;  
    }
    
    if(front == -1) front = 0;
    queue[++rear] = value;
    cout << "Inserted " << value << " into the queue." << endl;

  }
  
  /*
  2. DELETE (Dequeue)
Purpose: Remove and return the element at the front of the queue.

Algorithm Steps:
Check Underflow: If queue empty (front == -1 or front > rear), report underflow error.
Retrieve element: Get data at queue[front].
Move front pointer: Increment front to dequeue the element.
Reset when empty: If no elements left (front > rear), reset both front and rear to -1.
Return dequeued element.
*/
  int dequeue(){
    if(front == -1 || front > rear){
      cout << "Underflow! can't delete " << endl;
      return -1;
    }
    
    int data = queue[front++];
    
    if(front > rear){
      front = rear = -1;
      
    }
     cout << "Deleted " << data << " from the queue." << endl;
    return data;

  }
  
/*  
  3. SEARCH
Purpose: Check if an element exists in the queue.

Algorithm Steps:
If queue empty (front == -1), return false immediately.
Traverse from front to rear.
For each element, compare with key.
Return true if found; return false after complete traversal.
*/
  bool search(int val){
    if(front == -1 ){
      cout << "Queue is empty" << endl;
      return false;
    }
    
    for(int i = front ; i<= rear ; i++){
      if(val == queue[i]){
        return false ;
      }
    }
    
    return false;
  }
  
  bool isEmpty(){
    if(front == -1 || front > rear){
      cout << "Queue is Empty " << endl ;
      return true;
    }
    
    cout << "Queue is Not Empty " << endl;
    return false;
  }
  
  bool isFull(){
    if(rear == maxSize -1){
      cout << "Queue is Full " << endl;
      return true;
    }
      cout << "Queue is Not Full " << endl;
      return false;
  }
  
  void peek(){
    if(front == -1){
      cout << "Queue is empty no peek element" << endl;
      return;
    }
    cout << "Peek : " << queue[front] << endl;
  }
  
  void print(){
    if(front == -1 ){
      cout << " Can not print , Queue is Empty " << endl;
      return;
    }
    cout << "Elements of Queue : ";
    
    for(int i = front ; i<= rear ; i++){
      cout << queue[i] << " " ;
    }
    cout << endl;
  }
  
  
  
};

int main(){
 Queue q(5); 
  
  q.enqueue(4);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(7);
  q.enqueue(9);
  
  q.dequeue();
  q.dequeue();
  q.dequeue();
  
  q.isFull();
  q.isEmpty();
  q.peek();
  
  q.search(9);
  q.print();
  
}
