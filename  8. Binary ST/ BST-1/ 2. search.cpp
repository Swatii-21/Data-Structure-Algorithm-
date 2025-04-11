#include<iostream>
#include<vector>
using namespace std ;

class Node{
public:
   int data ;
   Node* left ; 
   Node* right ;
   
   Node(int data){
       this-> data = data;
       left = right = NULL;
   }
};

Node* insert(Node* root , int val){ //o(height)
    if(root == NULL){
        root = new Node(val);
        return root;
    }
    
    if(val < root ->data){
        root ->left = insert(root ->left , val);
    } else {
        root ->right = insert(root ->right , val);
    }
    
    return root ; 
}

Node* buildBST(int arr[] , int n ){
    Node* root = NULL;
    
    for(int i = 0 ; i <n ; i++){
        root = insert(root , arr[i]);
    }
    return root ; 
    
}

 bool search(Node* root , int key){ // O(height)
    if(root ==NULL){
        return false;
    }
    
    if(root->data == key){ //found
        return true; 
    }
    
    if(root -> data>key){
        return search(root ->left , key);
    } else {
        return search(root-> right , key);
    }
}
 


int main(){
    int arr[6]= { 5 , 1 , 3 , 4 , 2 , 7};
    
    Node* root = buildBST(arr , 6);
    
    cout << search(root , 15) << endl;
    return 0;
}