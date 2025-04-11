#include<iostream>
#include<vector>
using namespace std;

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
    idx++ ;  //IDX = -1 SE 0 HO GYI
    if(nodes[idx] == -1){ //INX PE 0 CHECK KIYA -1 TOH H NI AAGE CHLTE H 
        return NULL;
    }
    
    Node* currNode = new Node(nodes[idx]); //1 (AB IDHAR AA GYE  )
    currNode->left = buildtree(nodes); //2 (LEFT SUBTREE)
    currNode->right = buildtree(nodes); //3 (RIGHT SUBTREE)
    
    return currNode;
} 

//PREORDER TRAVERSAL 
void preorder(Node* root){
    if(root == NULL){
        return ; 
        
    }
    
    cout << root->data << " " ;
    preorder(root ->left ) ;
    preorder(root ->right) ; 
}

//INORDER TRAVERSAL
void inorder(Node* root){
    if(root == NULL){
        return ;
    }

    inorder(root ->left ) ;
    cout << root->data << " " ;
    inorder(root ->right) ; 
}

//POSTORDER TRAVERSAL 
void postorder(Node* root){
    if(root == NULL){
        return ;
    }
    
    postorder(root ->left ) ;
    postorder(root ->right) ;
    cout << root->data << " " ; 
    
}

int main(){
    vector<int> nodes = {1,2,4,-1 , -1 , 5 , -1 , -1 , 3 , -1 , 6 , -1 , -1};
    
    Node* root = buildtree(nodes);
    cout << "root = " << root ->data << endl;
    
    preorder(root);
    cout << endl;
    
    return 0;
}
