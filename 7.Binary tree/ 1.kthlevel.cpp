#include<iostream>
#include<vector>
using namespace std;
 
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
 
Node* buildTree(const vector<int>& nodes, int& index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        index++;
        return NULL;
    }

    Node* root = new Node(nodes[index++]);
    root->left = buildTree(nodes, index);
    root->right = buildTree(nodes, index);

    return root;
}

 
void kthHelper(Node* root, int k, int currLevel) {
    if (root == NULL) return;

    if (currLevel == k) {
        cout << root->data << " ";
        return;
    }

    kthHelper(root->left, k, currLevel + 1);
    kthHelper(root->right, k, currLevel + 1);
}

 
void kthLevel(Node* root, int k) {
    kthHelper(root, k, 1);
    cout << endl;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int index = 0;

    Node* root = buildTree(nodes, index);

    // Test for different K values
    cout << "Level 1: "; kthLevel(root, 1); // Output: 1
    cout << "Level 2: "; kthLevel(root, 2); // Output: 2 3
    cout << "Level 3: "; kthLevel(root, 3); // Output: 4 5 6

    return 0;
}
