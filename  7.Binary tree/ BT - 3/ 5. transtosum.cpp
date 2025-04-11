 #include<iostream>
using namespace std ;
#include <vector>


class Node {
public: 
      int data ; 
      Node* left ;
      Node* right ;
      
      Node(int data){
          this ->data = data;
          left = right = NULL;
      }
};

 static int idx = -1; //IDX = -1 

Node* buildtree(vector<int> nodes){
    idx++ ;  
    if(nodes[idx] == -1){  
        return NULL;
    } 
    Node* currNode = new Node(nodes[idx]);  
 
    currNode->left = buildtree(nodes); 
    currNode->right = buildtree(nodes);  
    
    return currNode;
} 

 
 int transform (Node* root){
     if (root == NULL){
          return 0;
      }
      
     int leftold = transform(root-> left);
     int rightold = transform(root-> right);
     int currold = root ->data ;
     
     root ->data = leftold+rightold ;
     
     if(root ->left != NULL)
      root -> data += root -> left ->data ;
      
      if(root -> right != NULL)
      root -> data += root ->right ->data ;
      
     return currold;
     
 }
 
 
 
 
 int main(){
     vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
     Node* root = buildtree(nodes);

     
   transform(root);
   levelorder(root);
      return 0;
 }
