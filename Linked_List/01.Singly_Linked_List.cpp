#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void insertNode(Node*& Head, int value) {
    Node* newNode = new Node(value);

    if (Head == nullptr) {
        Head = newNode;
    } else {
        Node* ptr = Head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }

    cout << "Inserted: " << value << endl;
}


void insertStartNode(Node*& Head,int value){
    Node* newNode = new Node(value);
    Node* second = Head;
    Head = newNode;
    
    Head->next = second ;

    cout << "Inserted at start: " << value << endl;
}

void insertBtwNode(Node*& head , int value , int after){
 
 if(head == nullptr  ){
   cout << "head is null" << endl;
   return;
 }
  Node* temp = head;
  
  while(temp != nullptr){
     if(temp->data == after){
        Node* newNode = new Node(value);
        Node* last = temp->next;
        temp->next = newNode;
        newNode->next = last;
        cout << "Node with value : " << value << " is inserted" << endl ;
        return;
     }
    
    temp = temp ->next;
  }
  
  cout << "Node with value " << after << " Not found in Linked List" << endl;
 
  return;
}

void deletionBtw(Node*& Head, int value){
    Node* box = Head ;
    while(box->next != nullptr){
        if(box->next->data == value){
            box->next = box->next->next;
        }
        box = box->next;
    }
    cout << "Deleted node with value: " << value << endl;
}

void deletionLast(Node*& Head){
    
    Node* box = Head;
    if(box == nullptr){
        return ;
    }
    
    if(box -> next == nullptr){
        Head = nullptr;
        return;
    }
    while(box->next != nullptr){
        if(box->next->next == nullptr){
            box->next = nullptr;
            break;
        }
        box = box->next;
    }
    cout << "Deleted last node." << endl;
}

void deleteFirst(Node*& Head){
    Node* Box = Head;
    Box = Head->next->next ;
    cout << "Deleted first node with value: " << Head->data << endl;
}

void printList(Node* Head) {
    Node* temp = Head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
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
    insertBtwNode(Head,999,20);
    deletionLast(Head);
    deletionBtw(Head,20);
    deleteFirst(Head);
    printList(Head);
}
