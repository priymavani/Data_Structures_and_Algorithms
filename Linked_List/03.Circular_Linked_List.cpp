#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void insertEnd(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    cout << "Inserted: " << value << endl;
}

void insertStart(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    head = newNode;
    cout << "Inserted at start: " << value << endl;
}

void insertAfter(Node* head, int after, int value) {
    if (head == nullptr) return;

    Node* temp = head;
    do {
        if (temp->data == after) {
            Node* newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Node with value " << after << " not found." << endl;
}

void deleteFirst(Node*& head) {
    if (head == nullptr) return;

    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    Node* temp = head;
    head = head->next;
    last->next = head;
    cout << "Deleted first node with value: " << temp->data << endl;
    delete temp;
}

void deleteLast(Node*& head) {
    if (head == nullptr) return;

    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }

    Node* toDelete = temp->next;
    temp->next = head;
    cout << "Deleted last node with value: " << toDelete->data << endl;
    delete toDelete;
}

void deleteNode(Node*& head, int value) {
    if (head == nullptr) return;

    if (head->data == value) {
        deleteFirst(head);
        return;
    }

    Node* temp = head;
    do {
        if (temp->next->data == value) {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            cout << "Deleted node with value: " << value << endl;
            delete toDelete;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

void printList(Node* head) {
    cout << "Circular Linked List: ";
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
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

    return 0;
}


