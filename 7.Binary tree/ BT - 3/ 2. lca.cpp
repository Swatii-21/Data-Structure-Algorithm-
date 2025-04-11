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

 bool roottonode(Node*root , int n , vector<int> &path){ //o(n)
     if(root == NULL){
         return false;
     }
     
     path.push_back(root ->data);
     if(root ->data == n){
         return true ;
     }
     
     bool isLeft = roottonode(root->left , n, path);
     bool isRight = roottonode(root->right , n, path);

     
     if(isLeft || isRight){
         return true ; 
     }
     
     path.pop_back();
     return false;
     
 }

 int lca(Node* root , int n1 , int n2){
     vector<int> path1;
     vector<int> path2;
     
     roottonode(root ,  n1 , path1 );
     roottonode(root ,  n2 , path2 );
     
     int i ; 
     int j ;
     int ans = -1;
    //  for(i = 0 ;  j = 0 ; i <= path1.size() && j<=path2.size() ; i++ ; j++ ;){
    //      if(path1[i] != path2[j]) {
    //          return lca;
    //      }
         
    //      lca = path1;
    //  }
    
     while(i < path1.size() && j < path2.size()){
        if(path1[i] != path2[j]){
            break;
        }
        ans = path1[i];
        i++;
        j++;
    }
    return ans;

 }

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

 int main(){
     vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
     Node* root = buildtree(nodes);

     
     int n1 = 4,  n2 =5;
     
     cout << "lca = " << lca(root , n1 , n2) <<endl;
     cout << "lca 2 = " << LCA2(root , n1 , n2 ) ->data << endl;
     return 0;
 }
