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

void printpath(vector<int> path){
    cout << "path: " ; 
    for(int i = 0 ;  i <path.size() ; i++){
        cout << path[i] << " ";
    }
    cout << endl;
}

void pathhelper(Node* root , vector<int> &path){
    if(root == NULL){
        return ; 
    }
    path.push_back(root ->data);
    
    if(root->left == NULL && root ->right == NULL){
        printpath(path);
        path.pop_back();
        return ;
    }
    
    pathhelper(root ->left , path);
    pathhelper(root ->right , path);
    
    path.pop_back();
}
void rootoleaf(Node* root) {
    vector<int> path ; 
pathhelper(root , path);
}

 int main()  {
    int arr[10] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node* root = buildBST(arr, 9);  // build full BST

     rootoleaf(root);

    return 0;
}
