#include<iostream>
#include<vector>
using namespace std ; 
 
 
class Node{
   public: 
   int data ; 
   Node* left;
   Node* right;
   
   Node(int data){
       this ->data = data;
       left = right = NULL;
   }
    
};

Node* insert(Node* root , int val){
    if(root == NULL){
        root = new Node(val);
        return root ; 
    }
    
    if(val < root->data){
        root -> left = insert (root -> left , val);
    }
    else {
        root ->right = insert(root ->right , val);
    }
    return root ; 
}

Node* buildBST(int arr[] , int n){
    Node* root = NULL;
    
    for(int i = 0 ;  i < n ; i++){
        root = insert(root , arr[i]);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return ;
    }
    
    inorder(root ->left);
    cout<< root ->data << " ";
    inorder( root ->right);
}

Node* getinordesucc(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* delNode(Node* root , int val){
    if(root == NULL){
        return NULL;
    }
    
    if(val < root ->data){ //leftsubtree
      root->left = delNode(root->left, val);
    } 
    else if(val > root ->data){
        root ->right = delNode(root ->right , val);
    } 
    else{
        //root == val
        //case1 : 0 children
        if(root ->left == NULL && root ->right == NULL){
            delete root ; 
            return NULL;
        }
        
        //case 2 : 1 children
        if(root ->left == NULL || root -> right == NULL){
            return root ->left == NULL ? root ->right : root ->left; 
        }
        
        //case3 : 2 childer
         
         Node* IS =  getinordesucc(root -> right);
         root ->data = IS -> data;
         root->right = delNode( root -> right , IS-> data);
         return root ; 
        
    }
    return root;
     
}


 int main() {
    int arr[10] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node* root = buildBST(arr, 9);  // build full BST

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    root = delNode(root, 4);   

    cout << "Inorder after deletion of 4: ";
    inorder(root);
    cout << endl;

    return 0;
}
