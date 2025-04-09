#include <iostream>
#include <queue>
using namespace std;

// Definition of a Node in the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
// pehla code 
void levelOrderTraversal(Node* root) {
    if (root == NULL) 
    return;

    queue<Node*> Q;
    Q.push(root);

    while (!Q.empty()) {
        Node* curr = Q.front();
        Q.pop();
        
        cout << curr->data << " ";

        if (curr->left != NULL){
           Q.push(curr->left);
        }

        if (curr->right != NULL){
            Q.push(curr->right);
        }

    cout << endl;
        
    }
}


// Function to perform level order traversal with new lines for each level
void levelOrderTraversal(Node* root) {
    if (root == NULL) 
    return;

    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);  // NULL marker to track the end of a level

    while (!Q.empty()) {
        Node* curr = Q.front();
        Q.pop();

        if (curr == NULL) {  // End of a level
            cout << endl;
            if (Q.empty()) break;  // If queue is empty, traversal is complete
            Q.push(NULL);  // Push NULL to mark the next level
        } else {
            cout << curr->data << " ";  // Print the node's data

            // Enqueue left and right children if they exist
            if (curr->left != NULL) Q.push(curr->left);
            if (curr->right != NULL) Q.push(curr->right);
        }
    }
}

// Main function to test the level order traversal
int main() {
    // Creating the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Perform level order traversal
    cout << "Level Order Traversal of the Binary Tree:\n";
    levelOrderTraversal(root);

    return 0;
}
