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
    
    //CREATE A NEW NODE WITH CURRENT VALUE 
    Node* currNode = new Node(nodes[idx]); //1 (AB IDHAR AA GYE  )

    //RECURSIVELY BUILD THE LEFT SUBTREE
    currNode->left = buildtree(nodes); //2 (LEFT SUBTREE)
    //RECURSIVELY BUILD THE RIGHT SUBTREE
    currNode->right = buildtree(nodes); //3 (RIGHT SUBTREE)
    
    return currNode;
} 

int main(){
    vector<int> nodes = {1,2,4,-1 , -1 , 5 , -1 , -1 , 3 , -1 , 6 , -1 , -1};
    
    Node* root = buildtree(nodes);
    cout << "root = " << root ->data << endl;
    
    return 0;
}
