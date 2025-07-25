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

Node* insertion(Node* root, int k) {
    if (root == nullptr) {
        return new Node(k);
    }

    if (k < root->data) {
        root->left = insertion(root->left, k);
    } else {
        root->right = insertion(root->right, k); 
    }
    cout << k << " inserted into the tree." << endl;
    return root;
}


void inorder(Node* root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void preorder(Node* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
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
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}


Node* searchLeaf(Node* root){
  if(root->right == nullptr) return root;
  
  return searchLeaf(root->right);
}

Node* remainNode(Node* root){
  if(root->left == nullptr) return root->right;
  if(root->right == nullptr) return root->left;
  
  Node* rightNode = root->right;
  Node* leftrightNode = searchLeaf(root->left);
  
  leftrightNode->right = rightNode;
  
  return root->left;
  
}


Node* deleteNode (Node* root, int k){
  if(root == nullptr) return nullptr;
  
  if(root -> data == k) return remainNode(root);
  
  Node* temp = root;
  
  while(temp!=nullptr){
    
    if(temp->data >k){
      
      if(temp->left!=nullptr && temp->left->data == k){
        temp->left = remainNode(temp->left);
        break;
      }
       else{
         temp=temp->left;
       }
       
    }
     else if(temp->data < k) {
       
       if(temp->right!=nullptr && temp->right->data == k){
        temp->right = remainNode(temp->right);
        break;
      }
       else{
         temp=temp->right;
       }
       
     }
  }
  cout << "Node with value " << k << " deleted." << endl;
  return root;
}


int main() {
    Node* root = nullptr;

    root = insertion(root, 10);
    insertion(root, 5);
    insertion(root, 15);
    insertion(root, 20);
    insertion(root, 12);
    deleteNode(root, 15); 

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
