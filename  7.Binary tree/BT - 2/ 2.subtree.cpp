#include <bits/stdc++.h>
#include<iostream>
#include<queue>
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

Node* buildtree(vector<int>& nodes, int& index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        index++;
        return NULL;
    }

    Node* root = new Node(nodes[index++]);
    root->left = buildtree(nodes, index);
    root->right = buildtree(nodes, index);

    return root;
}

//APPROACH 1 
/*bool issubtree(Node* root , Node* subRoot){
    if(root ->data == subRoot ->data){
        //identical for suvtrree
    }
    
    int isLeftSubtree = issubtree(root ->left , subRoot);
    
    if(!isLeftSubtree){
        return issubtree(root ->right , subRoot);
    }
    
    return true ; 
}
*/

//APPROACH2
/*bool issubtree(Node* root , Node* subRoot){
    if(root == NULL && subRoot ==NULL){
        return true ;
    } elseif(root ==NULL || subRoot ==NULL){
        return false;
    }
    
    
    if(root ->data == subRoot ->data){
        return isIdentical(root , subroot);
    }
    
    int isLeftSubtree = issubtree(root ->left , subRoot);
    
    if(!isLeftSubtree){
        return issubtree(root ->right , subRoot);
    }
    
    return true ; 
}
*/

bool isSubtree(Node* root, Node* subRoot) {
    if (root == NULL) {
        return false;
    }

    // If the trees are identical, then subRoot is a subtree of root
    if (isIdentical(root, subRoot)) {
        return true;
    }

    // Check recursively on left and right subtrees
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}


//idetical check krne ke liye 
bool isIdentical( Node* root1 , Node* root2){
    
    if(root1 ==NULL && root2 =NULL){
        return true;
    } 
    
    elseif( root1 ==NULL ||  root2 ==NULL){
        return false;
    }
    
    if(root1 ->data != root2 ->data){
        return false;
    }
    
    return isIdentical(root1 ->left , root2 ->left )&& isIdentical(root1->right, root2->right);
}


int main(){
    vector<int> nodes = {1,2 , 4 , -1 , -1 , 5 , -1 , -1 , 3 , -1 , 6 , -1 , -1};
    Node* root = buildtree(nodes);
    
    Node* subRoot = newNode(2);
    subRoot ->left = newNode(4);
    subRoot ->right = newNode(5);
    
    cout <<  isSubtree(root , subRoot) << endl;
}
