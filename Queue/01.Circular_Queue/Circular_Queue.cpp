#include <iostream>
#include <vector>
using namespace std;

class CircularQueue {
private:
    vector<int> queue;
    int front;
    int rear;
    int maxSize;
    int count;

public:
    CircularQueue(int size) {
        queue.resize(size);
        maxSize = size;
        front = -1;
        rear = -1;
        count = 0;
    }

    // Check if queue is full
    bool isFull() {
        return (count == maxSize);
    }

    // Check if queue is empty
    bool isEmpty() {
        return (count == 0);
    }
    
    
    /*
    1. Insert (Enqueue)
    Objective: Add an element at the rear of the circular queue.
    
    Algorithm Steps:
    1.Check Overflow Condition:
    Queue is full if: (rear + 1) \mod size = front - If full, enqueue not possible — report overflow. 
    2. If queue is empty (i.e., front == -1), initialize both front and rear to 0. 
    3. Otherwise, move rear forward circularly:
      rear = (rear + 1) \mod size  
    4. Place the new data at queue[rear]. 
    5. Confirm successful enqueue.
    */
  
    // Enqueue (Insert)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Overflow! Element " << value << " NOT inserted." << endl;
            return;
        }

        if (front == -1) {  
            front = rear = 0; 
        } else {
            rear = (rear + 1) % maxSize;
        }

        queue[rear] = value;
        count++;

        cout << "Inserted: " << value << endl;
    }
    
    /*
      2. Delete (Dequeue)
    Objective: Remove an element from the front of the circular queue.
    
    Algorithm Steps:
    1.Check if queue is empty (front == -1); if yes, report underflow.
    2.Retrieve the element at queue[front] to return or process.
    3.If there is only one element (front == rear), reset both pointers to -1.
    4.Otherwise, move front forward circularly:
      front = (front + 1) \mod size 
    5. Return or confirm the removed element.
    */

    // Dequeue (Delete)
    int dequeue() {
        if (isEmpty()) {
            cout << "Underflow! Queue is empty, cannot delete." << endl;
            return -1;
        }

        int data = queue[front];

        if (front == rear) {  
            front = rear = -1; 
        } else {
            front = (front + 1) % maxSize;
        }

        count--;

        cout << "Deleted: " << data << endl;
        return data;
    }

      /*
    3. Search
    Objective: Find if a given element exists in the circular queue.
    
    Algorithm Steps:
    1. If queue empty (front == -1), return false.
    2. Start from front.
    3. Move through queue elements circularly:
     i = (i + 1) \mod size 
    4. Compare each element with key. 
    5. Return true if found; if complete cycle ends without finding, return false.
      */
      
    // Search element
    bool search(int target) {
        if (isEmpty()) {
            cout << "Queue is empty, nothing to search." << endl;
            return false;
        }

        int index = front;
        for (int i = 0; i < count; i++) {
            if (queue[index] == target) {
                cout << "Element " << target << " FOUND in queue." << endl;
                return true;
            }
            index = (index + 1) % maxSize;
        }

        cout << "Element " << target << " NOT found in queue." << endl;
        return false;
    }

    // Display queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        int index = front;

        for (int i = 0; i < count; i++) {
            cout << queue[index] << " ";
            index = (index + 1) % maxSize;
        }

        cout << endl;
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(2);

    q.display();

    q.dequeue();
    q.dequeue();

    q.enqueue(10);
    q.enqueue(20);

    q.display();

    q.search(10);
    q.search(99);

    return 0;
}

  /*
  Output:
  
    Inserted: 5
    Inserted: 4
    Inserted: 3
    Inserted: 2
    Queue elements: 5 4 3 2 
    Deleted: 5
    Deleted: 4
    Inserted: 10
    Inserted: 20
    Queue elements: 3 2 10 20 
    Element 10 FOUND in queue.
    Element 99 NOT found in queue.
  */
