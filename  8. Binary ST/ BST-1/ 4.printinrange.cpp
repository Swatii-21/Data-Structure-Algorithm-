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

 

/*
void printinrange(Node* root , int start , int end ){
     if(root == NULL){
         return ; 
     }
    
    if(start <= root ->data && root ->data <= end){
           cout<< root ->data << " ";
           printinrange(root->left , start , end);
           printinrange(root ->right , start , end);
         } 
         else if(root ->data < start ){
           printinrange(root->right , start , end);
         } else {
           printinrange(root->left , start , end);
         }
       }
       */
       
///printinrnageforsortedsequence 
void printinrange(Node* root , int start , int end ){
     if(root == NULL){
         return ; 
     }
    
    if(start <= root ->data && root ->data <= end){
           printinrange(root->left , start , end);
           cout<< root ->data << " ";
           printinrange(root ->right , start , end);
         } 
         else if(root ->data < start ){
           printinrange(root->right , start , end);
         } else {
           printinrange(root->left , start , end);
         }
       }


 int main()  {
    int arr[10] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node* root = buildBST(arr, 9);  // build full BST

    printinrange(root , 5 , 12);

    return 0;
}
