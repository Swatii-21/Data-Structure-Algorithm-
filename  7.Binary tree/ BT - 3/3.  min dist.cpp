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

 
 //Approach 2 
Node* LCA2(Node* root , int n1 , int n2){
     if(root == NULL){
         return NULL;
     }
     
     if(root ->data == n1 || root -> data == n2){
         return root ; 
     }
     
     Node* leftLCA= LCA2(root -> left , n1 , n2);
     Node* rightLCA= LCA2(root -> right , n1 , n2);
     
     if(leftLCA != NULL && rightLCA != NULL){
         return root;
     }
     
     return leftLCA== NULL ? rightLCA : leftLCA;
 }
 
 int dist(Node* root , int n ){
     if(root == NULL){
         return -1;
     }
     
     if(root ->data == n){
         return 0;
     }
     
    int leftdist =  dist(root ->left , n);
    if(leftdist != -1){
        return leftdist +1;
    }
    
    int rightdist =  dist(root ->right , n);
    if(rightdist != -1){
        return rightdist +1;
    }
     
     return -1;
 }
 
 int minDis(Node* root , int n1 , int n2){
     Node* lca = LCA2(root , n1 , n2);
     
     int dist1= dist(lca , n1);
     int dist2 = dist(lca , n2);
     
     return dist1+ dist2 ;
 }
 
 
 
 int main(){
     vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
     Node* root = buildtree(nodes);

     
     int n1 = 4,  n2 =5;
     
    //  cout << "lca = " << lca(root , n1 , n2) <<endl;
    //cout << "lca 2 = " << LCA2(root , n1 , n2 ) ->data << endl;
    
    cout << "min dist = " << minDis(root , n1 , n2) << endl;
      return 0;
 }
