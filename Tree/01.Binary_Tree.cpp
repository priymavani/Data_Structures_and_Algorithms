// BINARY TREE 

//Insrtion
// Traversal
// Deletion of a node

#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insertion(int arr[], int& id, int size) {
    ++id;
    if (id >= size || arr[id] == -1) {
        return nullptr;
    }

    cout << arr[id] << " insert node" << endl;
    Node* newNode = new Node(arr[id]);

    newNode->left = insertion(arr, id, size);
    newNode->right = insertion(arr, id, size);

    return newNode;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " -> ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " -> ";
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " -> ";
    preorder(root->left);
    preorder(root->right);
}

void levelOrder(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty.\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}


void deleteLeaf(Node* root, Node* temp) {
    if (root == nullptr) return;

    queue<Node*> q;
    Node* temp1 = nullptr;
    q.push(root);

    while (!q.empty()) {
        Node* temp1 = q.front();
        q.pop();

      if(temp1 == temp){
        cout << "Deleting node with value: " << temp1->data << endl;
        delete temp1;

      }
      
      if(temp->left) q.push(temp->left);
      if(temp->right) q.push(temp->right);

    }    
  

}

void deleteNode(Node* root, int key) {
    if (root == nullptr) return;
    
    queue<Node*> q;
    Node* temp = nullptr;
    Node* temp1 = nullptr;

    q.push(root);

    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp->data == key) {
            temp1 = temp; 
        }

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
        }
        
    if (temp1 != nullptr) {
        int x = temp->data;           
        deleteLeaf(root, temp);       
        temp1->data = x;              
    }
}



int main() {
    int arr[] = {1, 2, -1, -1, 3, 4, -1, -1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int id = -1;

    Node* root = insertion(arr, id, size);

    deleteNode(root, 1); 
    cout << "\nPreorder Traversal: ";
    preorder(root);
    cout << endl;
    cout << "\nInorder Traversal: ";
    inorder(root);
    cout << endl;
    cout << "\nPostorder Traversal: ";
    postorder(root);
    cout << endl;
    cout << "\nLevel Order Traversal: ";
    levelOrder(root);

    return 0;
}
