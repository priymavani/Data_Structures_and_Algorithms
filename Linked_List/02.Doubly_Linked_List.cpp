#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev ;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

void insertNode(Node*& Head, int value) {
    Node* newNode = new Node(value);

   Node* ptr = Head;
   
   
    if (Head == nullptr) {
        Head = newNode;
    } else {
        Node* ptr = Head;
        
        while (ptr->next != nullptr) {
            ptr = ptr->next;
            
        }
         ptr->next = newNode;
        newNode->prev = ptr;
    }
    cout << "Inserted: " << value << endl;
}


void insertStartNode(Node*& Head, int value) {
    Node* newNode = new Node(value); 
    newNode->next = Head;            
    newNode->prev = nullptr;         

    if (Head != nullptr) {
        Head->prev = newNode;       
    }

    Head = newNode;      
    
    cout << "Inserted at start: " << value << endl;
}

void deleteFirst(Node*& Head) {
    if (Head == nullptr) return;

    Node* temp = Head;
    Head = Head->next;

    if (Head != nullptr)
        Head->prev = nullptr;

        cout << "Deleted first node with value: " << temp->data << endl;
        delete temp;
}

void deleteLast(Node*& Head) {
    if (Head == nullptr) return;

    Node* temp = Head;
    while (temp->next != nullptr)
        temp = temp->next;

    if (temp->prev != nullptr)
        temp->prev->next = nullptr;
    else
        Head = nullptr; // only one node

    cout << "Deleted last node with value: " << temp->data << endl;
    delete temp;
}

void deleteNode(Node*& Head, int value) {
    Node* temp = Head;

    while (temp != nullptr) {
        if (temp->data == value) {
            if (temp->prev)
                temp->prev->next = temp->next;
            else
                Head = temp->next;

            if (temp->next)
                temp->next->prev = temp->prev;

            delete temp;
            cout << "Deleted node with value: " << value << endl;
            return;
        }
        temp = temp->next;
    }
}


void printList(Node* Head) {
    Node* temp = Head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main(){
    Node* Head = nullptr;
    
    insertNode(Head,10);
    insertNode(Head,20);
    insertNode(Head,30);
    insertNode(Head,40);
    
    insertStartNode(Head, 80);
    insertStartNode(Head, 740);
    deleteNode(Head,999);
    deleteLast(Head);
    deleteNode(Head,20);
    deleteFirst(Head);
    printList(Head);
}