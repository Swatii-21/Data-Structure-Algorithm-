 #include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Define the structure for a tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to build a binary tree from vector input
Node* buildTree(vector<int>& nodes, int& index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        index++;
        return NULL;
    }

    Node* root = new Node(nodes[index++]);
    root->left = buildTree(nodes, index);
    root->right = buildTree(nodes, index);

    return root;
}

// Function to calculate the sum of all nodes in the tree
int sum(Node* root) {
    // Base case: If the node is null, return 0
    if (root == NULL) {
        return 0;
    }

    // Recursive calls to sum left and right subtrees
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);

    // Total sum at this node
    int currSum = leftSum + rightSum + root->data;
    
    return currSum;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1}; // Tree representation
    int index = 0;
    
    Node* root = buildTree(nodes, index);  // Build tree from input
    
    cout << "Sum of all nodes: " << sum(root) << endl;  // Compute and print sum
    
    return 0;
}

