 #include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* buildBSTfromsortedvec(vector<int> arr, int st, int end) {
    if (st > end) {
        return NULL;
    }

    int mid = st + (end - st) / 2;
    Node* curr = new Node(arr[mid]);

    curr->left = buildBSTfromsortedvec(arr, st, mid - 1);
    curr->right = buildBSTfromsortedvec(arr, mid + 1, end);

    return curr;
}

void getinorder(Node* root, vector<int>& nodes) { // Pass by reference
    if (root == NULL) {
        return;
    }

    getinorder(root->left, nodes);
    nodes.push_back(root->data);
    getinorder(root->right, nodes);
}

Node* mergeBST(Node* root1 , Node* root2) {
    vector<int> nodes1;
    vector<int> nodes2;
    vector<int> merged;
    
    getinorder(root1 , nodes1);
    getinorder(root2 , nodes2);
    
    int i = 0, j = 0;
    while(i < nodes1.size() && j < nodes2.size()) {
        if(nodes1[i] < nodes2[j]) {
            merged.push_back(nodes1[i++]);
        } else {
            merged.push_back(nodes2[j++]);
        }
    }
    
    while(i < nodes1.size()) {
        merged.push_back(nodes1[i++]);
    }
    
    while(j < nodes2.size()) {
        merged.push_back(nodes2[j++]);
    }
    
    return buildBSTfromsortedvec(merged, 0, merged.size() - 1);
}

// Preorder traversal function
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);
    
    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);  
    
    Node* root = mergeBST(root1, root2);  
    cout << endl;
    return 0;
}
