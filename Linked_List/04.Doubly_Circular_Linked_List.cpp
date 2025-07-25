#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

void insertEnd(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        cout << "Inserted: " << value << endl;
        return;
    }

    Node* last = head->prev;

    last->next = newNode;
    newNode->prev = last;
    newNode->next = head;
    head->prev = newNode;
    cout << "Inserted: " << value << endl;
}

void insertStart(Node*& head, int value) {
    insertEnd(head, value);
    head = head->prev; // newly inserted node becomes head
    cout << "Inserted at start: " << value << endl;
}

void insertAfter(Node* head, int after, int value) {
    if (head == nullptr) return;

    Node* temp = head;
    do {
        if (temp->data == after) {
            Node* newNode = new Node(value);
            Node* nextNode = temp->next;

            temp->next = newNode;
            newNode->prev = temp;

            newNode->next = nextNode;
            nextNode->prev = newNode;
            cout << "Inserted " << value << " after " << after << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Node with value " << after << " not found." << endl;
}

void deleteFirst(Node*& head) {
    if (head == nullptr) return;

    if (head->next == head) {
        cout << "Deleted first node with value: " << head->data << endl;
        delete head;
        head = nullptr;
        return;
    }

    Node* last = head->prev;
    Node* temp = head;

    head = head->next;
    head->prev = last;
    last->next = head;

    cout << "Deleted first node with value: " << temp->data << endl;
    delete temp;
}

void deleteLast(Node*& head) {
    if (head == nullptr) return;

    if (head->next == head) {
        cout << "Deleted last node with value: " << head->data << endl;
        delete head;
        head = nullptr;
        return;
    }

    Node* last = head->prev;
    Node* secondLast = last->prev;

    secondLast->next = head;
    head->prev = secondLast;

    cout << "Deleted last node with value: " << last->data << endl;
    delete last;
}

void deleteNode(Node*& head, int value) {
    if (head == nullptr) return;

    Node* temp = head;
    do {
        if (temp->data == value) {
            if (temp == head) {
                deleteFirst(head);
                return;
            }
            Node* prevNode = temp->prev;
            Node* nextNode = temp->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;

            cout << "Deleted node with value: " << value << endl;
            delete temp;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Node with value " << value << " not found." << endl;
}

void printListReverse(Node* head) {
    cout << "Circular Doubly Linked List (Reverse): ";
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* last = head->prev;
    Node* temp = last;
    do {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    } while (temp != last);
    cout << "(head)\n";
}


void printList(Node* head) {
    cout << "Circular Doubly Linked List: ";
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)\n";
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertStart(head, 5);
    insertAfter(head, 20, 25);

    deleteFirst(head);
    deleteLast(head);
    deleteNode(head, 20);

    printList(head);
    printListReverse(head);
    return 0;
}
